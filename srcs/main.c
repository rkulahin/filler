/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/23 17:19:07 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

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
				filler->dis[i][j] = 1000;
			j++;
		}
		i++;
	}
}

int		find_zero(t_filler *filler)
{
	int	i;
	int j;

	i = 0;
	while (i < filler->board->y)
	{
		j = 0;
		while (j < filler->board->x)
		{
			if (filler->dis[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	add_dist(t_filler *f, int y, int x, int k)
{
	if (x - 1 >= 0 && y - 1 >= 0 && f->dis[y - 1][x - 1] == 1000)
		f->dis[y - 1][x - 1] = k;
	if (x - 1 >= 0 && f->dis[y][x - 1] == 1000)
		f->dis[y][x - 1] = k;
	if (x - 1 >= 0 && y + 1 < f->board->y && f->dis[y + 1][x - 1] == 1000)
		f->dis[y + 1][x - 1] = k;
	if (x - 1 >= 0 && y - 1 >= 0 && f->dis[y - 1][x] == 1000)
		f->dis[y - 1][x] = k;
	if (x - 1 >= 0 && y + 1 < f->board->y && f->dis[y + 1][x] == 1000)
		f->dis[y + 1][x] = k;
	if (x + 1 < f->board->x && y - 1 >= 0 && f->dis[y - 1][x + 1] == 1000)
		f->dis[y - 1][x + 1] = k;
	if (x + 1 < f->board->x && f->dis[y][x + 1] == 1000)
		f->dis[y][x + 1] = k;
	if (x + 1 < f->board->x && y + 1 < f->board->y &&
	f->dis[y + 1][x + 1] == 1000)
		f->dis[y + 1][x + 1] = k;
}

void	find_distance_map(t_filler *filler)
{
	int		i;
	int		j;
	int		k;

	k = 1;
	while (k <= filler->maxdis)
	{
		i = 0;
		while (i < filler->board->y)
		{
			j = 0;
			while (j < filler->board->x)
			{
				if (filler->dis[i][j] == -1)
					add_dist(filler, i, j, k);
				else if (filler->dis[i][j] == k - 1 && k != 1)
					add_dist(filler, i, j, k);
				j++;
			}
			i++;
		}
		k++;
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

	i = 0;
	m = 0;
	minsum = 0;
	while (i < f->token->y)
	{
		j = 0;
		while (j < f->token->x)
		{
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
			j++;
		}
		i++;
	}
	if (m != 1)
		return (0);
	return (minsum);
}

void	find_position(t_filler *f)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (i < f->board->y)
	{
		j = 0;
		while (j < f->board->x)
		{
			k = past_token(f, i, j);
			if ((k < f->minsum && k != 0) || (f->minsum == 0 && k != 0))
			{
				f->minsum = k;
				f->x = i;
				f->y = j;
			}
			j++;
		}
		i++;
	}
	ft_printf("%i %i\n", f->x, f->y);
}

void	free_map(t_filler *f)
{
	int i;

	i = -1;
	while (i < f->board->y)
		free(f->board->map[i]);
	free(f->board->map);
	i = -1;
	while (++i < f->token->y)
		free(f->token->map[i]);
	free(f->token->map);
	i = -1;
	while (++i < f->board->y)
		free(f->dis[i]);
	free(f->dis);
	f->x = 0;
	f->y = 0;
	f->minsum = 0;
}

void	filler_algo(t_filler *filler)
{
	char	*line;
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
	g_fd = 0;
	if (get_next_line(g_fd, &line) && !ft_strncmp("$$$ exec p", line, 9))
	{
		filler->id = (line[10] == '1' ? 'O' : 'X');
		filler->unid = (line[10] == '1' ? 'X' : 'O');
		free(line);
	}
	filler_algo(filler);
	return (0);
}
