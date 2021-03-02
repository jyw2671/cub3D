/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:21:36 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:34:38 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player(t_cub3d *g, t_vec pos, int *flag)
{
	if (*flag)
		exit_cub3d_msg(g, "invaild map file");
	g->pos = pos;
	// pos -> 플레이어의 초기 위치벡터
	if (g->map.data[(int)pos.y][(int)pos.x] == 'N')
		g->dir = new_vec(0, -1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'S')
		g->dir = new_vec(0, 1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'W')
		g->dir = new_vec(-1, 0);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'E')
		g->dir = new_vec(1, 0);
	// dir -> 플레이어 초기 방향 벡터
	// 입력받은 초기 방향값에 따라 초기 방향 벡터를 설정해준다
	g->fov = FOV * M_PI_180;
	// FOV->66 (Field of view)(미니맵상 시야 방향 각도)
	// M_PI_180 -> pie값을 180으로 나눈 값 = 1도
	g->fov_h = g->v.width / 2 / tan(g->fov / 2);
	g->plane = rot_vec(g->dir, 90 * M_PI_180);
	// plane은 플레이어의 카메라평면
	// parsing 받은 플레이어의 방향 벡터에 따라 plane을 리셋한다
	g->plane.x *= tan(g->fov / 2);
	g->plane.y *= tan(g->fov / 2);
	*flag = 1;
	// FOV는 fov_h(방향 vec의 길이) : plane(카메라 평면 길이)의
	// 비율로 정해진다
}
// pos 벡터 : 플레이어의 위치
// dir 벡터 : 방향 벡터
// plane 벡터 : 전체 카메라평면 중 방향벡터의 끝점인 검정점으로 부터
	// 오른쪽의 카메라 평면 끝까지를 의미
// 방향 벡터의 끝점 : pos + dir
// 오른쪽 카메라 평면의 끝점 : (pos + dir) + plane
// 왼쪽 카메라 평면의 끝점 : (pos + dir) - plane

// 벡터를 회전시키기 위해선 벡터좌표와 회전행렬과 곱해주면된다
