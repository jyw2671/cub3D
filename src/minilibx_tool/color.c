/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:13:32 by yjung             #+#    #+#             */
/*   Updated: 2021/01/26 18:13:56 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		g_color = (t_color)0x00000000;

void	color_rgba(t_uc r, t_uc g, t_uc b, float a)
{
	if (a > 1)
		a = 1;
	g_color.bit.t = 255 - a * 255;
	g_color.bit.r = r;
	g_color.bit.g = g;
	g_color.bit.b = b;
}

t_color	rgba(t_uc r, t_uc g, t_uc b, float a)
{
	t_color		color;

	if (a > 1)
		a = 1;
	color.bit.t = 255 - a * 255;
	color.bit.r = r;
	color.bit.g = g;
	color.bit.b = b;

	return (color);
}
