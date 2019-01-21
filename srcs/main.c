/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/21 23:32:07 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_position(t_filler *filler, int y, int x)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (filler->board->map[x][y] == filler->id ||
		filler->board->map[x][y] == filler->id - ' ')
	{
		while (i < filler->token->y)
		{
			j = 0;
			while (j < filler->token->x)
			{
				if ((filler->board->map[x][y] == filler->id ||
		filler->board->map[x][y] == filler->id - ' ') &&
		filler->token->map[j][i] == '*');
					k++;
				if (filler->board->map[x][y] == filler->unid ||
		filler->board->map[x][y] != '.' ||
		filler->board->map[x][y] == filler->unid - ' ' || k > 1)
					//govno
				j++;
			}
			i++;
		}
	}
}

void	find_token_position(t_filler *filler)
{
	int		i;
	int		j;
	int		minsum;

	i = 0;
	while (i < filler->board->y)
	{
		j = 0;
		while (j < filler->board->x)
		{
			minsum = check_position(filler, i, j);
			if ((minsum < filler->minsum || filler->minsum == 0) && minsum != 0)
			{
				filler->x = j;
				filler->y = i;
				filler->minsum = minsum;
			}
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
	read_token_size(filler);
	find_token_position(filler);
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
		filler_algo(filler);
	}
}