/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:10:25 by yjung             #+#    #+#             */
/*   Updated: 2021/02/17 16:11:54 by yjung            ###   ########.fr       */
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
	exit(g ? code : 0);
}

void		exit_cub3d_msg(t_cub3d *g, char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	// 1번은 일반적인 프로그램의 출력 결과들이 나오게 되는 파이프 번호
	// 2번으로 보내게 되면 에러메세지를 전달하게 되는 파이프로 사용
	// 보통 터미널에서는 1번과 2번 둘다 보여주지만 파이프로 구분해서 보면
	// 에러메세지와 일반 출력 결과물을 구분 할 수 있어서
	// 오류가 난건지 무슨 문제가 있는지에 대해서 파악 할 수 있다

	// unistd.h 안에 존재하는 메크로 상수
	// STDIN_FILENO(0), STDOUT_FILENO(1), STDERR_FILENO(2)로 각각 정의되어 있다
	exit_cub3d(g, ERROR);
}
