/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:26:47 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/21 21:27:06 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_filler *filler, int x)
{
	int		i;
	char	*line;

	i = -1;
	if (x == 0)
	{
		get_next_line(g_fd, &line);
		filler->board->map = (char**)malloc(sizeof(char*) * filler->board->y);
		while(++i < filler->board->y)
		{
			get_next_line(g_fd, &line);
			filler->board->map[i] = ft_strchr(line, ' ') + 1;
			ft_printf("%s\n", filler->board->map[i]);
		}
		return ;
	}
	filler->token->map = (char**)malloc(sizeof(char*) * filler->token->y);
	while(++i < filler->token->y)
	{
		get_next_line(g_fd, &line);
		filler->token->map[i] = line;
		ft_printf("%s\n", filler->token->map[i]);
	}
}

void	read_board_size(t_filler *filler)
{
	char	*line;

	if (get_next_line(g_fd, &line))
	{
		filler->board->y = ft_atoi(ft_strchr(line, ' '));
		line = ft_strchr(line, ' ') + 1;
		filler->board->x = ft_atoi(ft_strchr(line, ' '));
	}
	ft_printf("%c %i %i\n", filler->id, filler->board->x, filler->board->y);
	read_map(filler, 0);
}

void	read_token_size(t_filler *filler)
{
		char	*line;

	if (get_next_line(g_fd, &line))
	{
		filler->token->y = ft_atoi(ft_strchr(line, ' '));
		line = ft_strchr(line, ' ') + 1;
		filler->token->x = ft_atoi(ft_strchr(line, ' '));
	}
	ft_printf("%c %i %i\n", filler->id, filler->token->x, filler->token->y);
	read_map(filler, 1);
}
