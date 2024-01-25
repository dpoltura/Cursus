# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/01/23 14:21:00 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRC =	main.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c
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