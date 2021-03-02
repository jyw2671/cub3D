/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:21:36 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 20:07:51 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub3d *g, t_vec pos, int *flag)
{
	if (*flag)
		exit_cub3d_msg(g, "invaild map file");
	g->pos = pos;
	if (g->map.data[(int)pos.y][(int)pos.x] == 'N')
		g->dir = new_vec(0, -1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'S')
		g->dir = new_vec(0, 1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'W')
		g->dir = new_vec(-1, 0);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'E')
		g->dir = new_vec(1, 0);
	g->fov = FOV * M_PI_180;
	g->fov_h = g->v.width / 2 / tan(g->fov / 2);
	g->plane = rot_vec(g->dir, 90 * M_PI_180);
	g->plane.x *= tan(g->fov / 2);
	g->plane.y *= tan(g->fov / 2);
	*flag = 1;
}
