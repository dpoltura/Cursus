# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/01/26 17:12:08 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRC =	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
INCLUDE = -L minilibx-linux -lmlx -lX11 -lXext -L libft -lft -L ft_printf -lftprintf
LIBFT = libft.a
FT_PRINTF = libftprintf.a
NAME = so_long

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

all: $(LIBFT) $(FT_PRINTF) $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re