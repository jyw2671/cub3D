/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_all_rays_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:21:50 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:35:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	cast_ray(t_cub3d *g, t_ray *ray)
{
	t_vec	side_d;
	t_vec	delta_d;
	t_ivec	step;
	int		hit;

	delta_d.x = fabsf(1 / ray->dir.x);
	// <math.h>의 함수 -> 절댓값을 만들어줌
	// 피타고라스의 정리를 이용하여 산출한 식
	delta_d.y = fabsf(1 / ray->dir.y);
	step = new_ivec(ray->dir.x < 0 ? -1 : 1, ray->dir.y < 0 ? -1 : 1);
	side_d.x = ray->dir.x < 0 ? (g->pos.x - ray->map.x) * delta_d.x :
				(ray->map.x + 1.0 - g->pos.x) * delta_d.x;
	side_d.y = ray->dir.y < 0 ? (g->pos.y - ray->map.y) * delta_d.y :
				(ray->map.y + 1.0 - g->pos.y) * delta_d.y;
	// (*) (1 - stepX) / 2 부분은 stepX가 -1, 1 인지에 따라 1, 0이 되는데 이는 rayDirX < 0 일 때
	// 길이에 1을 더해주기 위함이다
	// 즉 rayDirX < 0 이면 -> (mapX - posX + 1) / rayDirX 이다
 
	// delta_d.x : 첫번째 x면 ~ 바로 다음 만나는 x면 까지의 광선의 이동거리 (x는 1증가 (블럭 크기가 1))
	// delta_d.y : 첫번째 y면 ~ 바로 다음 만나는 y면 까지의 광선의 이동거리 (y는 1증가 (블럭 크기가 1))
	// side_d.x : 시작점 ~ 첫번째 x면을 만나는 점까지의 광선의 이동거리
	// side_d.y : 시작점 ~ 첫번째 y면을 만나는 점까지의 광선의 이동거리
	hit = 0;
	// hit : 부딪힌 여부에 대한 정보
		// x면에 부딪히면 side를 0, y면에 부딪히면 side를 1로 저장
	while (!hit)
	{
		if (side_d.x < side_d.y && !(ray->side = 0))
			((side_d.x += delta_d.x) || 1 ? (ray->map.x += step.x) : 0);
		else if ((ray->side = 1))
			((side_d.y += delta_d.y) || 1 ? (ray->map.y += step.y) : 0);
		(g->map.data[ray->map.y][ray->map.x] == '1' ? hit = 1 : 0);
	}
	// ray->dir : 광선의 방향벡터 (빨간 선)
		// ray->dir.x : 방향 벡터 + 카메라 평면 x 배수 → dirX + (planeX * cameraX) ↔ Y는 Y로 하면된다
	// delta_d.x = |1 / ray->dir.x| - 피타고라스의 정리를 이용하여 산출한 식 ↔ Y또한 그대로 하면된다
	ray->dist = (ray->side ?
		(ray->map.y - g->pos.y + (1 - step.y) / 2) / ray->dir.y :
		(ray->map.x - g->pos.x + (1 - step.x) / 2) / ray->dir.x);

	//  중심으로 광선을 쏘게 되면 하나의 평면상의 벽도 볼록 렌즈로 보는것처럼 둥그렇게 울어서 보일수 있다.
	//	따라서 유저가 속한 카메라 평면에서 수직의 선을 피사체에 그어서 해당 거리를 가지고 계산한다
		// side == 0 일 경우 (x면에 부딛힌경우)
		// -> ray->dist = (ray->map.x - g->pos.x + (1 - step.x) / 2) / ray->dir.x

		// side == 1 일 경우 (y면)
		// -> ray->dist = (ray->map.y - g->pos.y + (1 - step.y) / 2) / ray->dir.y

}

void		update_all_rays(t_cub3d *g)
{
	int		i;
	int		tex_i;
	float	camera_x;

	i = -1;
	while (++i < g->num_rays)
	// g->num_rays = g->v.width / WALL_STRIP_WIDTH;
	{
		camera_x = 2 * (i * WALL_STRIP_WIDTH) / (float)g->v.width - 1;
		// cameraX : 화면의 수직선(시야각에 존재하는 수직선)들의 x값이 카메라 평면에서 나타내는 x좌표이다
			// x값이 0이면 (스크린 왼쪽 끝) → cameraX = -1
			// x값이 w(화면폭) / 2 이면 (스크린 중앙) → cameraX = 0
			// x값이 w(화면폭)이면 (스크린 오른쪽 끝) → cameraX = 1
			// 식 : cameraX = 2 * (x / w) - 1

		// pos + dir + k * plane 값이 내가 쏴야할 광선인데,
		// cameraX는 plane에 곱할 상수(k)를 의미한다
		// 범위는 -1 부터 1까지이다 (나중에 더 찾아볼것!!!!)
		ft_memset(&g->rays[i], 0, sizeof(t_ray));
		g->rays[i].dir.x = g->dir.x + g->plane.x * camera_x;
		g->rays[i].dir.y = g->dir.y + g->plane.y * camera_x;
		g->rays[i].map = new_ivec(g->pos.x, g->pos.y);
		cast_ray(g, &g->rays[i]);
		if (g->rays[i].side)
			tex_i = g->rays[i].dir.y < 0 ? NO : SO;
		else
			tex_i = g->rays[i].dir.x < 0 ? EA : WE;
		g->rays[i].tex = &g->tex[tex_i];
	}
}


	// DDA알고리즘은 각 수직선을 계산할 때마다 x방향 or y방향으로 딱 한 칸씩 점프한다

	// 광선의 방향에 따라 오른쪽위인지 왼쪽위인지 정해야하는데 그 정보는 stepX, stepY에 +1, -1로 담아둔다
	// 벽의 x면, y면에 부딪혔는지의 여부에 따라 하나의 수직선이 벽을 찾는 루프문이 종료된다

	// hit : 부딪힌 여부에 대한 정보
	// x면에 부딪히면 side를 0, y면에 부딪히면 side를 1로 저장
	// stepX : rayDriX의 값에 따라 정해지는데 양수면 +1, 음수면 -1이다 (y또한 같다)

	// sideDistX의 값 산출

	// rayDirX가 양수면 오른쪽으로 가다 만난 x면까지의 거리이고
	// rayDirY가 음수이면 왼쪽으로 가다 만난 x면의 거리이다 ↔ sideDistY는 위아래로 생각하면된다

	// rayDirX가 양수 일 경우 : sideDistX = (mapX + 1 - posX ) x deltaDistX

	// rayDirX가 음수 일 경우 : sideDistX = (posX - mapX) x deltaDistX

	// posX는 시작점의 칸에서도 어느 x좌표에 있는지 알려주는 것이고 mapX는 시작점이 존재하는 칸의 x좌표이다



	//  중심으로 광선을 쏘게 되면 하나의 평면상의 벽도 볼록 렌즈로 보는것처럼 둥그렇게 울어서 보일수 있다.
	//	따라서 유저가 속한 카메라 평면에서 수직의 선을 피사체에 그어서 해당 거리를 가지고 계산한다

	// side == 0 일 경우 (x면에 부딛힌경우)
	// -> perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDriX

	// side == 1 일 경우 (y면)
	// -> perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY

	// (*) (1 - stepX) / 2 부분은 stepX가 -1, 1 인지에 따라 1, 0이 되는데 이는 rayDirX < 0 일 때
	// 길이에 1을 더해주기 위함이다
	// 즉 rayDirX < 0 이면 -> (mapX - posX + 1) / rayDirX 이다
	// 위 식을 통해 카메라 평면에서 피사체의 수직선까지의 수직거리를 구할수 있다

	// 유저의 카메라평면으로 부터 해당 벽의 거리의 수직 거리(ray->dist)를 이용해서 화면에 그려야할 선의 높이를 구하자

	// lineHeight = 스크린의 높이 / ray->dist
	// 거리가 멀~~~어질수록 스크린 대비 높이는 낮아진다

	// 스크린 높이의 중앙부 기준으로 시작과 끝은 잡는다
	// drawStart = (-lineHeight / 2) + 스크린높이/2  if (시작점이 0보다 작다면 0으로 고정)
	// drawEnd = (lineHeight / 2) + 스크린높이/2  if (끝점이 스크린 높이보다 크다면 스크린 높이로 고정)
