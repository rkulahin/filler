/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:26:47 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/24 09:38:43 by rkulahin         ###   ########.fr       */
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
		get_next_line(0, &line);
		free(line);

		filler->board->map = (char**)malloc(sizeof(char*) * filler->board->y);
		while (++i < filler->board->y)
		{
			get_next_line(0, &line);
			filler->board->map[i] = ft_strdup(ft_strchr(line, ' ') + 1);
			free(line);
		}
		return ;
	}
	filler->token->map = (char**)malloc(sizeof(char*) * filler->token->y);
	while (++i < filler->token->y)
	{
		get_next_line(0, &line);
		filler->token->map[i] = ft_strdup(line);
		free(line);
	}
}

int		read_board_size(t_filler *filler)
{
	char	*line;
	int		k;

	k = get_next_line(0, &line);
	if (k == 1)
	{
		filler->board->y = ft_atoi(ft_strchr(line, ' '));
		filler->board->x = ft_atoi(ft_strrchr(line, ' '));
		if (filler->board->y > filler->board->x)
			filler->maxdis = filler->board->y;
		else
			filler->maxdis = filler->board->x;
		free(line);
		read_map(filler, 0);
	}
	return (k);
}

void	read_token_size(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line))
	{
		filler->token->y = ft_atoi(ft_strchr(line, ' '));
		filler->token->x = ft_atoi(ft_strrchr(line, ' '));
		free(line);
	}
	read_map(filler, 1);
}
