/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:14:47 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 20:09:18 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_window(t_cub3d *g, int flag)
{
	if (!flag)
	{
		if (!(g->win =
			mlx_new_window(g->mlx, g->v.width, g->v.height, CUB3D_TITLE)))
			exit_cub3d_msg(g, "fail mlx_new_window()");
	}
	if (!(g->v.ptr = mlx_new_image(g->mlx, g->v.width, g->v.height)))
		exit_cub3d_msg(g, "fail mlx_new_image()");
	if (!(g->v.data = (t_color *)mlx_get_data_addr(
		g->v.ptr, &g->v.bpp, &g->v.size_l, &g->v.endian)))
		exit_cub3d_msg(g, "fail mlx_get_data_addr()");
	g->v.line = g->v.size_l / (g->v.bpp / 8);
}

void		init(t_cub3d *g, char *path, int flag)
{
	(!(g->mlx = mlx_init()) ? exit_cub3d_msg(g, "fail mlx_init()") : 0);
	mlx_get_screen_size(g->mlx, &g->v.width, &g->v.height);
	init_parse(g, path);
	init_window(g, flag);
	g->num_rays = g->v.width / WALL_STRIP_WIDTH;
	if (!(g->rays = malloc(sizeof(t_ray) * g->num_rays)))
		exit_cub3d_msg(g, "malloc failed");
}
