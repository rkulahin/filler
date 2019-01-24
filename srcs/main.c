/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/24 12:52:50 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				filler->dis[i][j] = 1000;
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

int		past_token(t_filler *f, int y, int x)
{
	int i;
	int	j;
	int m;
	int minsum;

	i = -1;
	m = 0;
	minsum = 0;
	while (++i < f->token->y && (j = -1) == -1)
		while (++j < f->token->x)
			if (i + y < f->board->y && j + x < f->board->x && m <= 1)
			{
				if (f->dis[y + i][x + j] == -1 && f->token->map[i][j] == '*')
					return (0);
				if (f->token->map[i][j] == '*' && f->dis[y + i][x + j] == -2)
					m++;
				else if (f->token->map[i][j] == '*')
					minsum += f->dis[i + y][j + x];
			}
			else
				return (0);
	if (m != 1)
		return (0);
	return (minsum);
}

void	filler_algo(t_filler *filler)
{
	int		k;

	k = 1;
	while (k == 1)
	{
		k = read_board_size(filler);
		if (k <= 0)
			return ;
		upcase_map(filler);
		read_token_size(filler);
		malloc_dis_map(filler);
		find_distance_map(filler);
		find_position(filler);
		free_map(filler);
	}
}

int		main(void)
{
	char		*line;
	t_filler	*filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	malloc_filler(filler);
	if (get_next_line(0, &line) && !ft_strncmp("$$$ exec p", line, 9))
	{
		filler->id = (line[10] == '1' ? 'O' : 'X');
		filler->unid = (line[10] == '1' ? 'X' : 'O');
		free(line);
	}
	filler_algo(filler);
	return (0);
}
