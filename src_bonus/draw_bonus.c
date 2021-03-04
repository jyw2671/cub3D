/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:54:55 by yjung             #+#    #+#             */
/*   Updated: 2021/03/04 22:00:07 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		line(t_img *view, t_vec a, t_vec b)
{
	long	distance;
	float	rad;

	rad = atan2f(b.y - a.y, b.x - a.x);
	distance = (long)sqrtf((b.x - a.x) * (b.x - a.x) + \
							(b.y - a.y) * (b.y - a.y));
	b.x = cos(rad);
	b.y = sin(rad);
	while (distance > 0)
	{
		a.x += b.x;
		a.y += b.y;
		put_pixel(view, a.x, a.y);
		--distance;
	}
}

void		rect(t_img *view, t_vec position, int width, int height)
{
	t_ivec	vec;
	int		i;
	int		j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			vec.x = position.x + i;
			vec.y = position.y + j++;
			put_pixel(view, vec.x, vec.y);
		}
		++i;
	}
}

void		mid_point_rect(t_img *view, t_vec position, int width, int height)
{
	t_ivec	vec;
	int		i;
	int		j;

	position.x -= width / 2;
	position.y -= height / 2;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			vec.x = position.x + i;
			vec.y = position.y + j++;
			put_pixel(view, vec.x, vec.y);
		}
		++i;
	}
}

void		put_pixel(t_img *view, int x, int y)
{
	int	index;

	index = y * view->line + x;
	view->data[index] = calc_rgba(view->data[index], g_color);
}
