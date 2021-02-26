/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:10:40 by yjung             #+#    #+#             */
/*   Updated: 2021/02/26 12:34:10 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "x_event_bonus.h"

# include "cub3d_type_bonus.h"
# include "cub3d_util_bonus.h"
# include "cub3d_init_bonus.h"
# include "cub3d_update_bonus.h"
# include "cub3d_render_bonus.h"

# include "key_mac_bonus.h"
# include "dummy_mac_bonus.h"

# define CUB3D_TITLE "yjung's cub3D"
# define WALL_STRIP_WIDTH 1
# define TILE 64
# define FOV 66
# define WALK_S 0.08
# define TURN_S 3

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

# define ERROR 1
# define SUCCES 0

# define M_2PI 6.28318530717958647692528676655900576
# define M_PI 3.14159265358979323846264338327950288
# define M_PI_2 1.57079632679489661923132169163975144
# define M_PI_4 0.785398163397448309615660845819875721
# define M_PI_180 0.017453292519943295769236907684886

# define BITMAPFILEHEADER 14
# define BITMAPINFOHEADER 40

int		save_bmp(t_cub3d *g);

int		handle_key_pressed(int keycode, t_cub3d *g);
int		handle_key_released(int keycode, t_cub3d *g);
int		handle_exit_window(t_cub3d *g);
int		handle_loop(t_cub3d *g);

void	exit_cub3d(t_cub3d *g, int code);
void	exit_cub3d_msg(t_cub3d *g, char *msg);

#endif
