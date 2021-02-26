/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:05:13 by yjung             #+#    #+#             */
/*   Updated: 2021/02/26 12:33:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INIT_BONUS_H
# define CUB3D_INIT_BONUS_H

# include "cub3d_bonus.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define F 5
# define C 6
# define R 7

extern t_uc g_parse_check;

void	init(t_cub3d *g, char *path, int flag);
void	init_parse(t_cub3d *g, char *path);
void	init_resolution(t_cub3d *g, char **split);
void	init_texture(t_cub3d *g, char *path, int tex_i);
void	init_bg_color(t_cub3d *g, char *line, int bg_i);
void	init_map(t_cub3d *g, int fd, char *line, int *check);
void	init_player(t_cub3d *g, t_vec pos, int *flag);
void	init_sprite(t_cub3d *g);

#endif
