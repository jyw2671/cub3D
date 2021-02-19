/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:00:19 by yjung             #+#    #+#             */
/*   Updated: 2021/02/20 01:08:12 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_cub3d *g, char *path, int tex_i)
{
	t_img	*img;

	if (((g_parse_check >> tex_i) & 1) == 1)
		exit_cub3d_msg(g, "invaild map file");
	// 정보가 중복되는지를 체크
	g_parse_check |= 1 << tex_i;
	// bit 연산으로 정보를 받은것을 체크
	img = &g->tex[tex_i];
	if (!(img->ptr = \
		mlx_xpm_file_to_image(g->mlx, path, &img->width, &img->height)))
		exit_cub3d_msg(g, "texture load fail");
	if (!(img->data = (t_color *)mlx_get_data_addr(\
			img->ptr, &img->bpp, &img->size_l, &img->endian)))
		exit_cub3d_msg(g, "texture data addr load fail..");
		// bpp, size_l, endian은 taelee님 mlx 예제 보고 따라함
		// 그냥 구조체안에 선언해놓고 잘넣어주기만 하면 값을 잘 받아나옴
		// mlx_get_data_addr 함수의 역할은...?
			// img_ptr과 int형 변수의 주소들을 넘겨주면 char형 배열의 주소 반환
			// (bpp)bits_per_pixel : 한 픽셀을 표현하는데 필요한 비트 수
			// size_l(size_line) : 이미지의 width를 표현하는데 필요한 바이트 수
			// endian : 리틀 엔디언일 시 0, 빅 엔디언일 시 1
			// 해당 배열에 접근하여 이미지 정보 수정 가능
	img->line = img->size_l / (img->bpp / 8);
	// line의 역할은..?
}
