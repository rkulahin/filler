# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 17:52:39 by rkulahin          #+#    #+#              #
#    Updated: 2019/01/24 13:58:21 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rkulahin.filler
OBJ_DIR = libftprintf/
SRC = 	srcs/main.c \
		srcs/read_data.c \
		srcs/dis_map.c
LIB = libftprintf.a
INCL = -I includes/
FLAGS =  -Wall -Wextra -Werror

all:
	$(MAKE) all -f ./libftprintf/Makefile
	@gcc $(INCL) $(FLAGS) -o $(NAME) $(SRC) $(LIB)
clean :
	$(MAKE) clean -f ./libftprintf/Makefile
fclean : clean
	$(MAKE) fclean -f ./libftprintf/Makefile
	@rm -f $(NAME);
re : fclean all
