# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:02:00 by dpoltura          #+#    #+#              #
#    Updated: 2023/11/23 13:47:22 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR= ./libft
LIBFT= $(LIBFT_DIR)/libft.a
CC= clang
CFLAGS= -Wall -Werror -Wextra
SRC=	ft_printf.c \
		ft_putnbr_x.c
OBJ= $(SRC:%.c=%.o)
NAME= libftprintf.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cp	$(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
