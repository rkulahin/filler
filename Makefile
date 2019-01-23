# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 17:52:39 by rkulahin          #+#    #+#              #
#    Updated: 2019/01/23 11:06:49 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rkulahin.filler
SRC = 	srcs/main.c \
		srcs/read_data.c
LIB = libftprintf.a
INCL = -I includes/
FLAGS =  -g

all:
	$(MAKE) re -f ./libftprintf/Makefile
	@gcc $(INCL) $(FLAGS) -o $(NAME) $(SRC) $(LIB)
clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -f $(NAME)	
re : fclean all
