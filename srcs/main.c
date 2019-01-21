/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/21 16:14:21 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_filler *filler)
{
	char	*line;

	if (get_next_line(g_fd, &line))
	{
		filler->board->sizey = ft_atoi(ft_strchr(line, ' '));
		line = ft_strchr(line, ' ') + 1;
		filler->board->sizex = ft_atoi(ft_strchr(line, ' '));
	}
}

void	malloc_filler(t_filler *filler)
{
	filler->player = 0;
	filler->minsum = 0;
	filler->coordx = 0;
	filler->coordy = 0;
	filler->token = (t_token*)malloc(sizeof(t_token));
	filler->board = (t_token*)malloc(sizeof(t_token));
}

void	filler_algo(t_filler *filler)
{
	read_map(filler);
	// read_token();
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
		filler->player = (line[10] == '1' ? 'O' : 'X');
		filler_algo(filler);
	}
}