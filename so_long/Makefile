# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/01/23 13:26:31 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRC = main.c
OBJ = $(SRC:%.c=%.o)
INCLUDE = -L minilibx-linux -lmlx -lX11 -lXext -L ../libft -lft
LIBFT = libft.a
NAME = so_long

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

$(LIBFT):
	$(MAKE) -C ../libft

all: $(LIBFT) $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C ../libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft/ fclean

re: fclean all

.PHONY: all clean fclean re