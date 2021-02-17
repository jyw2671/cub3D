/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:11:02 by yjung             #+#    #+#             */
/*   Updated: 2021/01/26 18:11:07 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_UTIL_H
# define MINILIBX_UTIL_H

# include "cub3d.h"

extern t_color	g_color;
extern t_color	g_stroke;
extern t_color	g_fill;
extern int		g_no_stroke;

t_color	rgba(t_uc r, t_uc g, t_uc b, float a);
void	fill_rgba(t_uc r, t_uc g, t_uc b, float a);
void	stroke_rgba(t_uc r, t_uc g, t_uc b, float a);
void	color_rgba(t_uc r, t_uc g, t_uc b, float a);
void	no_stroke(void);

t_color	calc_rgba(t_color background, t_color color);
void	put_pixel(t_img *view, int x, int y);

void	line(t_img *view, t_vec a, t_vec b);
void	rect(t_img *view, t_vec position, int width, int height);
void	mid_point_rect(t_img *view, t_vec position, int width, int height);

#endif
