/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:15:10 by yjung             #+#    #+#             */
/*   Updated: 2021/02/21 02:27:27 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_key_pressed(int keycode, t_cub3d *g)
{
	(keycode == KEY_W ? g->key.w = 1 : 0);
	(keycode == KEY_A ? g->key.a = 1 : 0);
	(keycode == KEY_S ? g->key.s = 1 : 0);
	(keycode == KEY_D ? g->key.d = 1 : 0);
	(keycode == KEY_SPACE ? g->key.space = 1 : 0);
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
	(keycode == KEY_SPACE ? g->key.space = 0 : 0);
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
// 	g->m_map.img = mlx_new_image(g->mlx, (int)(g->v.width / 5), (int)(g->v.height / 5));
// 	g->m_map.data = (int *)mlx_get_data_addr(g->m_map.img, &g->m_map.bpp, &g->m_map.size_l, &g->m_map.endian);
// 	mlx_put_image_to_window(g->mlx, g->win, g->m_map.img, 0, 0);
// }

int		handle_loop(t_cub3d *g)
{
	update(g);
	render(g);
	mlx_put_image_to_window(g->mlx, g->win, g->v.ptr, 0, 0);
	// 파일로부터 이미지 만드는 함수
	// 이미지를 읽기 위해서는 XMP파일이거나 PNG 파일 형식이어야 함
	// mlx_xpm_file_to_image 혹은 mlx_png_file_to_image가 있는데
	// png함수는 현재 메모리 누수라고 함 -> 그래서 xpm파일을 다들 읽는 거 였음
	// if (g->key.space == 1)
	// 	update_mini_map(g);
	mlx_do_sync(g->mlx);
	return (0);
}
