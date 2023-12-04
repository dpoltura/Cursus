# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 12:56:28 by dpoltura          #+#    #+#              #
#    Updated: 2023/12/04 10:08:10 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang

CFLAGS= -Wall -Werror -Wextra -g

SRC=	get_next_line.c \
		get_next_line_utils.c \
		main.c \

OBJ= $(SRC:%.c=%.o)

NAME= a.out

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
