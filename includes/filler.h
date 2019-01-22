/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:37:13 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/22 17:48:57 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libftprintf/includes/ft_printf.h"
# include <fcntl.h>

int						g_fd;
typedef struct			s_token
{
	char				**map;
	int					x;
	int					y;
}						t_token;

typedef struct			s_filler
{
	t_token				*board;
	t_token				*token;
	int					**dis;
	int					id;
	int					unid;
	int					x;
	int					y;
	int					minsum;
}						t_filler;

void					read_map(t_filler *filler, int x);
void					read_board_size(t_filler *filler);
void					read_token_size(t_filler *filler);
void					filler_algo(t_filler *filler);
void					malloc_filler(t_filler *filler);
void					find_distance_map(t_filler *filler);
void					printmap(t_filler *f);

#endif