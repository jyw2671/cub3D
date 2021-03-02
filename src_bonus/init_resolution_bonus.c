/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:58:36 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:34:42 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	itoa(t_cub3d *g, char *word)
{
	int		len;
	int		n;

	n = 0;
	len = ft_strlen(word);
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0)
		exit_cub3d_msg(g, "parsing error resolution");
	return (n);
}

void		init_resolution(t_cub3d *g, char **split)
{
	t_ivec	resolution;

	if (((g_parse_check >> R) & 1) == 1)
		exit_cub3d_msg(g, "invaild map file");
	g_parse_check |= 1 << R;
	resolution.x = itoa(g, split[0]);
	resolution.y = itoa(g, split[1]);
	if (resolution.x < g->v.width)
		g->v.width = resolution.x;
	if (resolution.y < g->v.height)
		g->v.height = resolution.y;
	// g->m.width = (int)(g->v.width / 6);
	// g->m.height = (int)(g->v.height / 6);
	// 그냥 인자로 받은 해상도 정보가 문자이므로 itoa 해줘서
	// 문자->숫자 정보로 바꿔서 저장해줌
}
