/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:19:45 by yjung             #+#    #+#             */
/*   Updated: 2021/02/25 17:34:48 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_uc	g_parse_check = 0;
// init.h 파일에 이미 extern 해놓음
	// extern -> 이미 외부에 있는 변수를 사용하겟다

static void		ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

static void		switch_parse(t_cub3d *g, char **split, int word_cnt)
{
	if (!ft_strcmp(split[0], "R") && word_cnt == 3)
		init_resolution(g, &split[1]);
	else if (!ft_strcmp(split[0], "NO") && word_cnt == 2)
		init_texture(g, split[1], NO);
	else if (!ft_strcmp(split[0], "SO") && word_cnt == 2)
		init_texture(g, split[1], SO);
	else if (!ft_strcmp(split[0], "EA") && word_cnt == 2)
		init_texture(g, split[1], EA);
	else if (!ft_strcmp(split[0], "WE") && word_cnt == 2)
		init_texture(g, split[1], WE);
	else if (!ft_strcmp(split[0], "S") && word_cnt == 2)
		init_texture(g, split[1], S);
	else if (!ft_strcmp(split[0], "F") && word_cnt == 2)
		init_bg_color(g, split[1], F);
	else if (!ft_strcmp(split[0], "C") && word_cnt == 2)
		init_bg_color(g, split[1], C);
	else
		exit_cub3d_msg(g, "invaild map file");
}
	// 해상도를 나타내는 R element 에서는 init_resolution으로 들어가
	// t_cub3d 구조체의 v(t_img)안에 정보를 저장
	// 나머지 elements 들은

static void		check_parse_type(t_cub3d *g, char *line)
{
	int		word_cnt;
	// 한 줄에 알맞은 정보들이 들어왔는지를 확인해주는 역할
	char	**split;

	if (ft_strlen(line))
	{
		if (!(split = ft_split_cnt(line, ' ', &word_cnt)))
			exit_cub3d_msg(g, "malloc failed");
			// char **split에 공백으로 ft_split_cnt 한것을 할당받는다
		switch_parse(g, split, word_cnt);
		// 올바른 내용이 들어왔는지를 확인하고 조건이 충족될때 각각의 조건문으로 들어가게 된다
		ft_free_arr(split, word_cnt);
		// 다 쓴 char **split free 시켜줌
	}
	free(line);
}

static int		extention_check(char *path)
{
	int		len;

	if ((len = ft_strlen(path)) < 4)
		return (ERROR);
	// 인자가 들어오는 시점은 컴파일 후여서
	// 코드 내부에서 예외 상황을 생각해서 처리해 주어야 한다
	// 여기서는 확장자만 확인을 하고 맵 파일의 에러는 나중에 처리
	if (path[len - 1] == 'b' && path[len - 2] == 'u' \
		&& path[len - 3] == 'c' && path[len - 4] == '.')
		return (SUCCES);
	return (ERROR);
}

void			init_parse(t_cub3d *g, char *path)
{
	int		fd;
	int		check;
	char	*line;

	if (extention_check(path))
		exit_cub3d_msg(g, "invaild file extension. (.cub)");
	if ((fd = open(path, O_RDONLY)) == -1)
		exit_cub3d_msg(g, "file open fail...");
	// open(const char *pathname, int flags);
		// pathname -> open할 파일명에 대한 fullpath 또는 상대 path
		// flags -> 파일을 어떤 목적으로 open할 것이며, 파일의 초기화할 지 여부등을 지정
		// O_RDONLY : 읽기 전용으로 open
		// O_WRONLY : 쓰기 전용으로 open
		// O_RDWR : 읽고 쓰기를 모두 할 수 있도록 open
		// 위의 내용을 쓰기 위해서는 <fcntl.h>를 include 해야 한다
	// 여기서의 path는 .cub 파일의 경로
	while ((g_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
		check_parse_type(g, line);
		// check_parse_type 함수는 line 값을 역참조로 넣어준것이 아니므로
		// line의 값은 계속 누적되서 저장되고 있다

	// 의문점 -> (g_parse_check != 0xFF)
	// g_parse_check != 0xFF -> 0xFF : 16진법 256
	// (check = get_next_line(fd, &line)) >= 0 -> gnl이 에러가 아니면

	// parsing이 각 항목이 중첩되어서 파싱되는 것을 방지 하는 거랑
	// 추가로 모든 정보가 파싱 끝나는 지를 bit 연산으로 확인 하도록 해두었음
	// 예를 들어서 해상도는 상수로 0으로 지정해두고 g_parse_check >> 0 & 1 했을때
	// 1이면 파싱이 된걸로 오류 처리 0이면 파싱이 안되어 있으니 파싱하고 1로 세팅
	// 모든 항목이 전부 파싱이 끝나면 255로 되어서 반복문을 탈출 하도록 해두었음
	if (check < 0)
		exit_cub3d_msg(g, !check ? "invaild map file" : "file read error");
	while ((check = get_next_line(fd, &line)) > 0 && !ft_strlen(line))
		free(line);
	// 첫번째 while문은 map 전까지의 정보를 parsing 하고 그 다음 while문은 map 정보를 parsing 한다
	init_map(g, fd, line, &check);
	init_sprite(g);
	close(fd);
}
