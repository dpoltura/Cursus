# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:02:00 by dpoltura          #+#    #+#              #
#    Updated: 2023/11/17 11:13:41 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT= libft
CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC=	ft_printf.c \
		main.c
OBJ= $(SRC:%.c=%.o)
NAME= libftprintf.a

all: $(NAME)
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ) -lft

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re