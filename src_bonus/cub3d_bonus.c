/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:09:21 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:34:11 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	// 사용자 정의 이벤트 핸들러
	mlx_loop_hook(g.mlx, handle_loop, &g);
	// 아무 이벤트도 발생하지 않았을때 전달된 함수 실행
	mlx_loop(g.mlx);
	// event 입력을 대기하며 절대 반환되지 않는 무한루프
	return (0);
}
// int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
	// 사용자 정의 이벤트 핸들러 (전달한 함수로 처리한다)
	// x_event : 키 press, release, x버튼 press 등 원하는 이벤트 설정 가능
		// X_KEY_PRESS -> 입력할 때, 입력하는 동안
		// X_KEY_RELEASE -> 땔 때
	// x_mask : 무시한다 (0으로 놔둠)
	// (*funct)() : 원하는 기능의 함수 포인터
	// param : 함수로 넘겨줄 변수
