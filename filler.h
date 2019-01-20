/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:37:13 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/20 13:52:30 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct			s_token
{
	char				*map;
	int					sizeX;
	int					sizeY;
}						t_token;

typedef struct			s_filler
{
	t_token				board;
	t_token				token;
	int					player;
	int					coordX;
	int					coordY;
	int					minsum;
}						t_filler;

#endif