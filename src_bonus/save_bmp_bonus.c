/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:19:39 by yjung             #+#    #+#             */
/*   Updated: 2021/02/17 18:19:42 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_header(t_cub3d *g, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER +
		(g->v.bpp / 8) * g->v.width * g->v.height;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &g->v.width, 4);
	ft_memmove(&info[8], &g->v.height, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &g->v.bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void	bmp_data(t_cub3d *g, int fd)
{
	int		x;
	int		y;

	y = g->v.height;
	while (y-- > 0)
	{
		x = -1;
		while (++x < g->v.width)
			write(fd, &g->v.data[y * g->v.line + x].i, 4);
	}
}

int			save_bmp(t_cub3d *g)
{
	int		fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		exit_cub3d_msg(g, "can't (create | open) image.bmp file");
	update(g);
	render(g);
	bmp_header(g, fd);
	bmp_data(g, fd);
	close(fd);
	return (SUCCES);
}
