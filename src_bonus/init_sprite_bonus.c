/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:59:45 by yjung             #+#    #+#             */
/*   Updated: 2021/03/02 15:34:45 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parsing_sprite(t_cub3d *g, t_list **lst, t_list **curr)
{
	int			i;
	t_sprite	*tmp;

	*lst = 0;
	i = -1;
	while (++i < g->map.w * g->map.h)
	{
		if (g->map.data[i / g->map.w][i % g->map.w] == '2')
		{
			// map parsing 내용 중에서 2인 부분을 찾는다
			if (!(tmp = malloc(sizeof(t_sprite))))
				exit_cub3d_msg(g, "malloc failed");
			tmp->pos = new_vec(i % g->map.w + 0.5, i / g->map.w + 0.5);
			// 중앙에서 부터 시작하기 때문에 0.5씩을 더해준다
			// sprite의 위치 좌표
			tmp->tex = &g->tex[S];
			// 역참조로 저장된 정보 넘겨줌
			if (!*lst)
				(!(*lst = ft_lstnew(tmp)) ?
					exit_cub3d_msg(g, "malloc failed") : 0);
			else if (!(*curr = ft_lstnew(tmp)))
				exit_cub3d_msg(g, "malloc failed");
			else
				ft_lstadd_back(lst, *curr);
		}
	}
}

void	init_sprite(t_cub3d *g)
{
	int			i;
	t_list		*lst;
	t_list		*curr;

	parsing_sprite(g, &lst, &curr);
	g->num_sp = ft_lstsize(lst);
	// sprite의 갯수	sprite? (sprite + 1)?
	if (!(g->sp = malloc(sizeof(t_sprite) * g->num_sp)) ||
		!(g->sp_order = malloc(sizeof(int) * g->num_sp)) ||
		!(g->sp_dist = malloc(sizeof(float) * g->num_sp)))
		exit_cub3d_msg(g, "malloc failed");
	curr = lst;
	i = -1;
	while (++i < g->num_sp)
	{
		g->sp[i] = *(t_sprite *)curr->content;
		curr = curr->next;
	}
	ft_lstclear(&lst, free);
}
