/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:06:51 by yjung             #+#    #+#             */
/*   Updated: 2021/02/26 12:33:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UPDATE_BONUS_H
# define CUB3D_UPDATE_BONUS_H

# include "cub3d_bonus.h"

void	update(t_cub3d *g);
void	update_player(t_cub3d *g);
void	update_all_rays(t_cub3d *g);
void	update_sprite(t_cub3d *g);

#endif
