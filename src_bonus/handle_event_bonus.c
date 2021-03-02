/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:15:10 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 19:07:45 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		handle_key_pressed(int keycode, t_cub3d *g)
{
	(keycode == KEY_W ? g->key.w = 1 : 0);
	(keycode == KEY_A ? g->key.a = 1 : 0);
	(keycode == KEY_S ? g->key.s = 1 : 0);
	(keycode == KEY_D ? g->key.d = 1 : 0);
	(keycode == KEY_SPACE ? g->key.space = !g->key.space : 0);
	(keycode == KEY_UP ? g->key.up = 1 : 0);
	(keycode == KEY_DOWN ? g->key.down = 1 : 0);
	(keycode == KEY_LEFT ? g->key.left = 1 : 0);
	(keycode == KEY_RIGHT ? g->key.right = 1 : 0);
	if (keycode == KEY_ESC)
		exit_cub3d(g, SUCCES);
	return (0);
}

int		handle_key_released(int keycode, t_cub3d *g)
{
	(keycode == KEY_W ? g->key.w = 0 : 0);
	(keycode == KEY_A ? g->key.a = 0 : 0);
	(keycode == KEY_S ? g->key.s = 0 : 0);
	(keycode == KEY_D ? g->key.d = 0 : 0);
	(keycode == KEY_UP ? g->key.up = 0 : 0);
	(keycode == KEY_DOWN ? g->key.down = 0 : 0);
	(keycode == KEY_LEFT ? g->key.left = 0 : 0);
	(keycode == KEY_RIGHT ? g->key.right = 0 : 0);
	return (0);
}

int		handle_exit_window(t_cub3d *g)
{
	exit_cub3d(g, SUCCES);
	return (0);
}

// static void	update_mini_map(t_cub3d *g)
// {
// 	g->m.ptr = mlx_new_image(g->mlx, g->m.width, g->m.height);
// 	g->m.data = (t_color *)mlx_get_data_addr(g->m.ptr, &g->m.bpp, \
// 		&g->m.size_l, &g->m.endian);
// 	g->m.line = g->m.size_l / (g->m.bpp / 8);
// 	mlx_put_image_to_window(g->mlx, g->win, g->m.ptr, 0, 0);
// }

int		handle_loop(t_cub3d *g)
{
	update(g);
	render(g);
	mlx_put_image_to_window(g->mlx, g->win, g->v.ptr, 0, 0);
	// if (g->key.space == 1)
	// 	update_mini_map(g);
	mlx_do_sync(g->mlx);
	return (0);
}
