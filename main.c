/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:23:19 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/20 16:00:28 by rkulahin         ###   ########.fr       */
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

int		main(void)
{
    char		*line;
	t_filler	*filler;

	malloc_filler(filler);
}