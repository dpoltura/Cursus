# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 09:53:05 by dpoltura          #+#    #+#              #
#    Updated: 2024/03/16 12:04:22 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror -g -Wno-unused-command-line-argument

SRCS = 	minishell.c \
		ft_split.c \
		utils.c \
		utils_2.c \
		directory.c \
		parse.c
OBJS = $(SRCS:%.c=%.o)

NAME = minishell

INCLUDES = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
