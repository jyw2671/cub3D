/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:02:00 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 18:12:57 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_floor(t_cub3d *g)
{
	g_color = g->bg_color[F - F];
	// g->bg_color[0];
	rect(&g->v, new_vec(0, g->v.height / 2), g->v.width, g->v.height / 2);
}
