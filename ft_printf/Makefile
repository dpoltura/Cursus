# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:02:00 by dpoltura          #+#    #+#              #
#    Updated: 2023/11/16 13:18:37 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS= -Wall -Werror -Wextra

SRC=	ft_printf.c \
		ft_putstr.c \
		ft_putnbr.c \
		main.c

OBJ= $(SRC:%.c=%.o)

NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re