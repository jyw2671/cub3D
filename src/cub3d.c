/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:09:21 by yjung             #+#    #+#             */
/*   Updated: 2021/02/17 22:57:34 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int		main(void)
// {
// 	t_cub3d		g;

// 	init(&g, 720, 480, CUB3D_TITLE);
// 	mlx_hook(g.win, X_KEY_PRESS, X_KEY_PRESS_MASK, handle_key_pressed, &g);
// 	mlx_hook(g.win, X_KEY_RELEASE, X_KEY_RELEASE_MASK, handle_key_released, &g);
// 	mlx_hook(g.win, X_DESTROY_NOTIFY,
// 			X_SUB_STRUCTURE_NOTIFY_MASK, handle_exit_window, &g);
// 	mlx_loop_hook(g.mlx, handle_loop, &g);
// 	mlx_loop(g.mlx);
// 	return (0);
// }

int		main(int ac, char **av)
{
	int			flag;
	t_cub3d		g;

	flag = !ft_strcmp(av[1], "--save");
	// ./cub3dD --save map.cub -> av[1] == --save av[2] == map.cub
	// ./cub3dD map.cub -> av[1] == map.cub
	// !ft_strcmp(av[1], "--save") ... !
	// 이므로 av[1]이 "--save"이면 0 아니면 1이 flag에 저장된다
	ft_memset(&g, 0, sizeof(t_cub3d));
	// 구조체 초기화 작업
	if (ac < 2)
		exit_cub3d_msg(&g, "require map file");
	// map file require
	init(&g, av[1 + flag], flag);
	if (flag)
		return (save_bmp(&g));
	// bmp 저장
	mlx_hook(g.win, X_KEY_PRESS, X_KEY_PRESS_MASK, handle_key_pressed, &g);
	mlx_hook(g.win, X_KEY_RELEASE, \
		X_KEY_RELEASE_MASK, handle_key_released, &g);
	mlx_hook(g.win, X_DESTROY_NOTIFY,
			X_SUB_STRUCTURE_NOTIFY_MASK, handle_exit_window, &g);
	mlx_loop_hook(g.mlx, handle_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
