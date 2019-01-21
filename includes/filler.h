/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:37:13 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/21 16:13:55 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libftprintf/includes/ft_printf.h"
#	include <fcntl.h>

int						g_fd;
typedef struct			s_token
{
	char				**map;
	int					sizex;
	int					sizey;
}						t_token;

typedef struct			s_filler
{
	t_token				*board;
	t_token				*token;
	int					player;
	int					coordx;
	int					coordy;
	int					minsum;
}						t_filler;

#endif