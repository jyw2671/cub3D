/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:21:36 by yjung             #+#    #+#             */
/*   Updated: 2021/02/20 01:25:46 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub3d *g, t_vec pos, int *flag)
{
	if (*flag)
		exit_cub3d_msg(g, "invaild map file");
	g->pos = pos;
	// pos -> 플레이어의 초기 위치벡터
	if (g->map.data[(int)pos.y][(int)pos.x] == 'N')
		g->dir = new_vec(0, -1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'S')
		g->dir = new_vec(0, 1);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'W')
		g->dir = new_vec(-1, 0);
	else if (g->map.data[(int)pos.y][(int)pos.x] == 'E')
		g->dir = new_vec(1, 0);
	// dir -> 플레이어 초기 방향 벡터
	// 입력받은 초기 방향값에 따라 초기 방향 벡터를 설정해준다
	g->fov = FOV * M_PI_180;
	// FOV->66 (미니맵상 시야 방향 각도)
	// M_PI_180 -> pie값을 180으로 나눈 값 = 1도
	g->fov_h = g->v.width / 2 / tan(g->fov / 2);
	g->plane = rot_vec(g->dir, 90 * M_PI_180);
	// plane은 플레이어의 카메라평면
	g->plane.x *= tan(g->fov / 2);
	g->plane.y *= tan(g->fov / 2);
	*flag = 1;
}
