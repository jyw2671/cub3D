/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:05:59 by yjung             #+#    #+#             */
/*   Updated: 2021/02/17 15:06:02 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H

# include "cub3d.h"

void	render(t_cub3d *g);
void	render_floor(t_cub3d *g);
void	render_ceiling(t_cub3d *g);
void	render_wall(t_cub3d *g);
void	render_sprite(t_cub3d *g);

#endif
