/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:15:22 by yjung             #+#    #+#             */
/*   Updated: 2021/03/04 22:11:26 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		render(t_cub3d *g)
{
	render_floor(g);
	render_ceiling(g);
	render_wall(g);
	render_sprite(g);
	if (g->key.space)
		render_mini_map(g);
}
