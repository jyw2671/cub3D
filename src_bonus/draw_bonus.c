/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:54:55 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 19:07:39 by yjung            ###   ########.fr       */
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
	// t_color g_color = (t_color)0x00000000;
}

// void		put_pixel_map(t_img *view, int x, int y)
// {
// 	int	index;

// 	index = y * view->line + x;
// 	view->data[index] = calc_rgba(view->data[index], g_color);
// 	// t_color g_color = (t_color)0x00000000;
// }

	// // mlx_get_data_addr 함수의 역할은...?
	// 		// img_ptr과 int형 변수의 주소들을 넘겨주면 char형 배열의 주소 반환
	// 		// (bpp)bits_per_pixel : 한 픽셀을 표현하는데 필요한 비트 수
	// 		// size_l(size_line) : 이미지의 width를 표현하는데 필요한 바이트 수
	// 		// endian : 리틀 엔디언일 시 0, 빅 엔디언일 시 1
	// 		// 해당 배열에 접근하여 이미지 정보 수정 가능
	// img->line = img->size_l / (img->bpp / 8);
		// (img->bpp / 8) -> bit를 byte로
		// 한 줄에 몇개의 픽셀이 있는지를 구함
	// // line의 역할은..?
	// 	// 이 부분은 배열에서 화면에 보이는 한줄에 대해서 저장을 width로만 하는 것이 아니라
	// 	// mms 라이브러리에서는 padding를 추가하여서 저장을 하게 되는데
	// 	// 그래서 실제 array 에서 [y * width + x]  이렇게 접근을 했을 때 제대로 접근이 안되는 문제가 있어서
	// 	// 위에 적혀진 공식으로 실제 line의 값을 구해서 y의 위치를 제대로 구할 수 있도록 한것
