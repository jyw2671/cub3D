/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:09:21 by yjung             #+#    #+#             */
/*   Updated: 2021/03/04 21:47:00 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		main(int ac, char **av)
{
	int		flag;
	t_cub3d	g;

	flag = !ft_strcmp(av[2], "--save");
	ft_memset(&g, 0, sizeof(t_cub3d));
	if (ac < 2)
		exit_cub3d_msg(&g, "require map file");
	else if ((ac > 2 && !flag) || ac > 3)
		exit_cub3d_msg(&g, "enter invaild command");
	init(&g, av[1], flag);
	if (flag)
		return (save_bmp(&g));
	mlx_hook(g.win, X_KEY_PRESS, 0, handle_key_pressed, &g);
	mlx_hook(g.win, X_KEY_RELEASE, 0, handle_key_released, &g);
	mlx_hook(g.win, X_DESTROY_NOTIFY, 0, handle_exit_window, &g);
	mlx_loop_hook(g.mlx, handle_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
