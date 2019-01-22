/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/22 14:33:48 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	upcase_map(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->board->y)
	{
		j = 0;
		while (j < filler->board->x)
		{
			filler->board->map[i][j] = ft_toupper(filler->board->map[i][j]);
			j++;
		}
		i++;
	}
}

void	malloc_dis_map(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	filler->dis = (int**)malloc(sizeof(int *) * filler->board->y);
	while (i < filler->board->y)
	{
		j = 0;
		filler->dis[i] = (int*)malloc(sizeof(int) * filler->board->x + 1);
		while (j < filler->board->x)
		{
			if (filler->board->map[i][j] == filler->unid)
				filler->dis[i][j] = -1;
			else if (filler->board->map[i][j] == filler->id)
				filler->dis[i][j] = -2;
			else
				filler->dis[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	find_distance_map(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->board->y)
	{
		j = 0;
		while (j < filler->board->x)
		{
			if (filler->board->map[i][j] == filler->unid)
			j++;
		}
		i++;
	}
}

void	malloc_filler(t_filler *filler)
{
	filler->id = 0;
	filler->minsum = 0;
	filler->x = 0;
	filler->y = 0;
	filler->token = (t_token*)malloc(sizeof(t_token));
	filler->board = (t_token*)malloc(sizeof(t_token));
}

void	filler_algo(t_filler *filler)
{
	read_board_size(filler);
	upcase_map(filler);
	read_token_size(filler);
	malloc_dis_map(filler);
	find_distance_map(filler);
}

int		main(void)
{
	char		*line;
	t_filler	*filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	malloc_filler(filler);
	g_fd = open("fl", O_RDWR);
	if (get_next_line(g_fd, &line) && !ft_strncmp("$$$ exec p", line, 9))
	{
		filler->id = (line[10] == '1' ? 'O' : 'X');
		filler->unid = (line[10] == '1' ? 'X' : 'O');
		free(line);
		filler_algo(filler);
	}
}