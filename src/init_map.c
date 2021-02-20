/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:41:18 by yjung             #+#    #+#             */
/*   Updated: 2021/02/21 00:36:57 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map_setup(t_cub3d *g, int size, int max, t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	if (!(g->map.data = malloc(sizeof(char **) * size)))
		exit_cub3d_msg(g, "malloc failed");
	g->map.w = max;
	g->map.h = size;
	// line 마다 연결리스트로 연결해 놓았으므로 lst의 갯수가 높이가 된다
	i = -1;
	while (++i < size)
	{
		if (!(g->map.data[i] = malloc(max + 1)))
			exit_cub3d_msg(g, "malloc failed");
		ft_memset(g->map.data[i], ' ', max);
		ft_memmove(g->map.data[i], curr->content, ft_strlen(curr->content));
		g->map.data[i][max] = 0;
		curr = curr->next;
	}
	ft_lstclear(&lst, free);
}

static void	init_map_parsing(t_cub3d *g, int fd, char *line, int *check)
{
	int		max;
	t_list	*curr;
	t_list	*tmp;

	if (!(curr = ft_lstnew(line)))
		exit_cub3d_msg(g, "malloc failed");
	// ft_lstnew : 새로 만든 list의 포인터를 반환한다
	max = ft_strlen(line);
	while ((*check = get_next_line(fd, &line)) >= 0 && ft_strlen(line))
	{
		if (!(tmp = ft_lstnew(line)))
			exit_cub3d_msg(g, "malloc failed");
		ft_lstadd_back(&curr, tmp);
		// lstadd_back : 연결리스트의 끝에 새로운 요소를 추가하는 함수
			// lst 의 가장 마지막 next 에 new 를 담아줌.
			// t_list **lst : 첫 번째 연결리스트의 포인터 주소
			// t_list *new : 요소가 될 포인터 주소
			// lst 나 new 가 NULL일 경우, return 으로 함수를 종료함.
			// lst 만 NULL일 경우, new 를 lst 에 담아주고 함수를 종료함.
		max = max > (int)ft_strlen(line) ? max : ft_strlen(line);
	}
	if (*check == -1)
		exit_cub3d_msg(g, "file read error");
	free(line);
	init_map_setup(g, ft_lstsize(curr), max, curr);
	// .cub file에 저장된 map 정보 내용에 각 줄의 끝부분과 그 다음줄의 처음부분만을 리스트로 연결해뒀으면..?
	// ft_lstsize는 세로, max는 가로 맵 길이가 된다
}

static void	check_map(t_cub3d *g, t_ivec p)
{
	t_map	*m;

	m = &g->map;
	if (!ft_strchr(" 012NSWE", m->data[p.y][p.x]) ||
		((p.y == 0 || p.x == 0 || p.y == m->h - 1 || p.x == m->w - 1) &&
		!ft_strchr(" 1", m->data[p.y][p.x])))
		exit_cub3d_msg(g, "invaild map file");
	if (m->data[p.y][p.x] == ' ')
	{
		if ((p.y != 0 && !ft_strchr(" 1", m->data[p.y - 1][p.x])) ||
			(p.x != 0 && !ft_strchr(" 1", m->data[p.y][p.x - 1])) ||
			(p.y < m->h - 1 && !ft_strchr(" 1", m->data[p.y + 1][p.x])) ||
			(p.x < m->w - 1 && !ft_strchr(" 1", m->data[p.y][p.x + 1])))
			exit_cub3d_msg(g, "invaild map file");
	}
	// p.x -> 열(row), p.y -> 행(col)
}

void		init_map(t_cub3d *g, int fd, char *line, int *check)
{
	int		i;
	int		flag;

	init_map_parsing(g, fd, line, check);
	// 2차원배열에 맵을 저장해서 만들어야 하는데 맵의 길이하고 라인수를 알 수가 없어서
	// 일단 리스트에 저장을 하고 난 다음에 max와 linked lst의 사이즈를 활용해서
	// 2차원 배열에 재할당 시키도록 하는 함수
	flag = 0;
	// player position이 잘 parsing이 됬는지 확인해준다
	// error check 하는 숫자
	i = -1;
	while (++i < g->map.w * g->map.h)
	{
		check_map(g, new_ivec(i % g->map.w, i / g->map.w));
		// map 검사 - 뚫린곳은 없는지 등등
		// i % g->map.w => 열(row), i / g->map.w => 행(col)
		if (ft_strchr("NSWE", g->map.data[i / g->map.w][i % g->map.w]))
			init_player(g,
				new_vec(i % g->map.w + 0.5, i / g->map.w + 0.5), &flag);
		// player의 시작 위치를 찾아서 설정해준다
		// 입력받은 방향에 맞춰 벡터를 회전시켜준다
		// 의문점 - 열과 행을 구하는건 알겟는데 0.5씩 더해주는 이유는..?
	}
	if (!flag)
		exit_cub3d_msg(g, "parsing player postion error");
}
