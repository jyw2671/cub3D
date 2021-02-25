/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bg_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:59:12 by yjung             #+#    #+#             */
/*   Updated: 2021/02/22 17:17:57 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

static int	itoa(t_cub3d *g, char *word)
{
	int		len;
	int		n;

	n = 0;
	if (!(len = ft_strlen(word)))
		exit_cub3d_msg(g, "parsing error background color");
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0 || n > 256)
		exit_cub3d_msg(g, "parsing error background color");
	return (n);
}

void		init_bg_color(t_cub3d *g, char *line, int bg_i)
{
	int		word_cnt;
	char	**split;

	if (((g_parse_check >> bg_i) & 1) == 1)
		exit_cub3d_msg(g, "invaild map file");
	g_parse_check |= 1 << bg_i;
	if (!(split = ft_split_cnt(line, ',', &word_cnt)) && word_cnt != 3)
		exit_cub3d_msg(g, word_cnt != 3 ? "invaild map file" : "malloc failed");
	g->bg_color[bg_i - F].i = 0;
	g->bg_color[bg_i - F].bit.r = itoa(g, split[0]);
	g->bg_color[bg_i - F].bit.g = itoa(g, split[1]);
	g->bg_color[bg_i - F].bit.b = itoa(g, split[2]);
	ft_free_arr(split, word_cnt);
}
