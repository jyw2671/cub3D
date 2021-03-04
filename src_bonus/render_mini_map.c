/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:28:43 by yjung             #+#    #+#             */
/*   Updated: 2021/03/04 21:44:48 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_map(t_cub3d *g, int size, t_vec obj, float step)
{
	t_ivec	iv;

	iv.y = -1;
	while (++iv.y < size)
	{
		obj.x = g->pos.x - 6;
		iv.x = -1;
		while (++iv.x < size)
		{
			if (0 <= obj.x && obj.x < g->map.w && \
				0 <= obj.y && obj.y < g->map.h)
			{
				if (g->map.data[(int)(obj.y)][(int)obj.x] == '1')
					g_color = rgba(123, 123, 123, 0.5);
				else if (g->map.data[(int)(obj.y)][(int)obj.x] == '2')
					g_color = rgba(180, 180, 180, 0.5);
				else
					g_color = rgba(12, 12, 12, 0.5);
				put_pixel(&g->v, iv.x, iv.y);
			}
			obj.x += step;
		}
		obj.y += step;
	}
}

void		render_mini_map(t_cub3d *g)
{
	int		size;
	float	step;
	t_vec	obj;

	size = g->v.height > g->v.width ?
		g->v.width / 6 : g->v.height / 6;
	obj = new_vec(g->pos.x - 6, g->pos.y - 6);
	step = ((g->pos.x + 6) - obj.x) / size;
	g_color = rgba(200, 200, 200, 1);
	render_map(g, size, obj, step);
	g_color = rgba(1, 100, 123, 1);
	mid_point_rect(&g->v, new_vec(size / 2, size / 2), size / 15, size / 15);
}
