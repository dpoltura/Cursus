# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/01/11 12:23:57 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAG = -Wall -Werror -Wextra

SRC = main.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = -Lminilibx-linux -lmlx -lX11 -lXext

NAME = so_long

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(INCLUDE) -o $(NAME)

all : $(NAME)

clean :
	rm -r $(OBJ)

fclean : clean
	rm -r $(NAME)

re : fclean all

.PHONY : all clean fclean re