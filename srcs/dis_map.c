/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:21:51 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/24 09:32:40 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_filler *f)
{
	int i;

	i = -1;
	while (++i < f->board->y)
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
