/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:01:27 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:35:01 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_ceiling(t_cub3d *g)
{
	g_color = g->bg_color[C - F];
	rect(&g->v, new_vec(0, 0), g->v.width, g->v.height / 2);
}
