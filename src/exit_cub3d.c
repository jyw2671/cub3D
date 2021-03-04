/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:10:25 by yjung             #+#    #+#             */
/*   Updated: 2021/03/04 19:09:26 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_free(void *memory)
{
	if (memory)
		free(memory);
}

void		exit_cub3d(t_cub3d *g, int code)
{
	int		i;

	i = -1;
	while (++i < 7)
		(g->tex[i].ptr ? mlx_destroy_image(g->mlx, g->tex[i].ptr) : 0);
	check_free(g->rays);
	check_free(g->sp);
	check_free(g->sp_order);
	check_free(g->sp_dist);
	i = -1;
	while (++i < g->map.h)
		check_free(g->map.data[i]);
	(g->v.ptr ? mlx_destroy_image(g->mlx, g->v.ptr) : 0);
	(g->win ? mlx_destroy_window(g->mlx, g->win) : 0);
	(g->mlx ? mlx_destroy_display(g->mlx) : 0);
	system("leaks cub3D");
	exit(g ? code : 0);
}

void		exit_cub3d_msg(t_cub3d *g, char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit_cub3d(g, ERROR);
}
