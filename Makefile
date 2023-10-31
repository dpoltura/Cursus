# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 15:37:33 by dpoltura          #+#    #+#              #
#    Updated: 2023/10/31 16:01:53 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wextra -Wall -Werror -g
NAME=libft.a

all: $(NAME)

$(NAME): main.o ft_bzero.o ft_isascii.o ft_memcpy.o ft_strlen.o ft_isalnum.o ft_isdigit.o ft_memmove.o ft_strlcat.o ft_tolower.o ft_isalpha.o ft_isprint.o ft_memset.o ft_strlcpy.o ft_toupper.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean:
	rm -rf $(NAME)
