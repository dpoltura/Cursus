# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/02/07 09:37:43 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRC =	main.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
INCLUDE = -L lib/minilibx-linux -lmlx -lX11 -lXext -L lib/libft -lft -L lib/ft_printf -lftprintf
LIBFT = libft.a
FT_PRINTF = libftprintf.a
NAME = so_long

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

$(LIBFT):
	$(MAKE) -C lib/libft

$(FT_PRINTF):
	$(MAKE) -C lib/ft_printf

all: $(LIBFT) $(FT_PRINTF) $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re