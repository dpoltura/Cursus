# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 08:46:25 by dpoltura          #+#    #+#              #
#    Updated: 2024/01/16 08:56:29 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wextra -Werror -Wall

SRCS = 	init.c \
		push_swap.c \
		push.c \
		rotate.c \
		security.c \
		swap.c \
		utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = push_swap

all : $(OBJS) $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -r $(OBJS)

fclean : clean
	rm -r $(NAME)

re : fclean all

.PHONY : all clean fclean re