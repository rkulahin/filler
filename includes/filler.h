/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:37:13 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/24 09:39:30 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libftprintf/includes/ft_printf.h"

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
	int					maxdis;
}						t_filler;

void					read_map(t_filler *filler, int x);
int						read_board_size(t_filler *filler);
void					read_token_size(t_filler *filler);
void					filler_algo(t_filler *filler);
void					malloc_filler(t_filler *filler);
void					find_distance_map(t_filler *filler);
void					printmap(t_filler *f);
void					upcase_map(t_filler *filler);
void					malloc_dis_map(t_filler *filler);
void					add_dist(t_filler *f, int y, int x, int k);
int						past_token(t_filler *f, int y, int x);
void					find_position(t_filler *f);
void					free_map(t_filler *f);

#endif
