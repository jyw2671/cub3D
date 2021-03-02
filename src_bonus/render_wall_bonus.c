/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:02:56 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 17:58:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_wall_texture(t_cub3d *g, t_ray *ray, t_vec pos, int wall_h)
{
	int		y;
	t_ivec	iv;
	float	step;
	t_vec	tex_p;

	tex_p.x = ray->side ? g->pos.x + ray->dist * ray->dir.x :
		g->pos.y + ray->dist * ray->dir.y;
	// x에 광선이 닿은건지 y에 닿은건지 판별한 값(ray->side)으로 다른 값을 받음
	tex_p.x = (int)((tex_p.x - floor(tex_p.x)) * ray->tex->width);
	if ((!ray->side && ray->dir.x < 0) || (ray->side && ray->dir.y > 0))
		tex_p.x = ray->tex->width - tex_p.x - 1;
	step = (float)ray->tex->height / wall_h;
	(pos.y < 0 ? (pos.y = 0) : 0);
	tex_p.y = (pos.y - g->v.height / 2 + wall_h / 2) * step;
	(wall_h > g->v.height ? (wall_h = g->v.height - 1) : 0);
	iv.y = 0;
	while (iv.y < wall_h)
	{
		y = ((int)tex_p.y & ray->tex->height - 1);
		g_color = ray->tex->data[y * ray->tex->line + (int)tex_p.x];
		iv.x = 0;
		while (iv.x < WALL_STRIP_WIDTH)
			put_pixel(&g->v, pos.x + iv.x++, pos.y + iv.y);
		// 지금은 WALL_STRIP_WIDTH가 1이라 while문을 한번밖에 안돌지만
		// 혹시 WALL_STRIP_WIDTH가 더 큰 수가 들어왔을때를 위해서
		tex_p.y += step;
		iv.y++;
	}
}

void		render_wall(t_cub3d *g)
{
	int		i;
	int		wall_h;
	t_vec	pos;

	i = -1;
	while (++i < g->num_rays)
	// g->num_rays = g->v.width / WALL_STRIP_WIDTH;
	{
		wall_h = g->fov_h / g->rays[i].dist;
		// g->fov_h는 방향벡터의 길이
		// = ray->dis
		pos.x = i * WALL_STRIP_WIDTH;
		// 화면상의 x좌표
		// 화면 왼쭉끝부터 0부터 시작한다
		// 마찬가지로 화면상의 y좌표도 상단이 0부터 시작한다
		// 왼쪽 상단이 (0.0)
		pos.y = g->v.height / 2 - wall_h / 2;
		// pos -> 찍기 시작할 위치
			// 여길 기준으로 벽을 세운다
		render_wall_texture(g, &g->rays[i], pos, wall_h);
		// &g->rays[i] -> 역참조로 넣어서 값을 받아오기 위함
	}
}
