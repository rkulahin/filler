/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/20 16:12:34 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	malloc_filler(t_filler *filler)
{
	filler = malloc(sizeof(t_filler));
	filler->player = 0;
	filler->minsum = 0;
	filler->coordX = 0;
	filler->coordY = 0;
	filler->token = malloc(sizeof(t_token));
	filler->board = malloc(sizeof(t_token));
}

void	read_map_token(t_filler *filler)
{

}

int		main(void)
{
    char		*line;
	t_filler	*filler;

	malloc_filler(filler);
	if (get_next_line(0, *line) && !ft_strncmp("$$$ exec p", line, 9))
	{
		filler->player = (line[10] == '1' ? 'O' : 'X');
		ft_strdel(*line);
		read_map_token(filler);
	}
}