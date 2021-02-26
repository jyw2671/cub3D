/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:15:22 by yjung             #+#    #+#             */
/*   Updated: 2021/02/26 12:37:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	render_minimap(t_cub3d *g)
// {

// }

void		render(t_cub3d *g)
{
	render_floor(g);
	// 화면을 반 색칠한다 (바닥)
	render_ceiling(g);
	// 화면을 반 색칠한다 (천장)
	render_wall(g);
	render_sprite(g);
	if (g->key.space == 1)
		render_mini_map(g);
	// render_minimap(g);
}

	// img.img_ptr = mlx_xpm_file_to_image(set->mlx, path, &img.width, &img.height);
	// img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	// for(int y = 0; y < img.height; y++)
	// {
	// 	for(int x = 0; x < img.width; x++)
	// 		set->info.texture[texNum][img.width * y + x] = img.data[img.width * y + x];
	// }
	// mlx_destroy_image(set->mlx, img.img_ptr);


	// set.win = mlx_new_window(set.mlx, set.minfo.s_width, set.minfo.s_height, "cub3d");
	// set.img.img_ptr = mlx_new_image(set.mlx, set.minfo.s_width, set.minfo.s_height);
	// set.img.data = (int *)mlx_get_data_addr(set.img.img_ptr, &set.img.bpp, &set.img.size_l, &set.img.endian);
