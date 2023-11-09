# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:23:33 by dpoltura          #+#    #+#              #
#    Updated: 2023/11/09 11:27:10 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ= $(SRC:%.c=%.o)

CFLAGS= -g -Wall -Werror -Wextra

CC= cc

NAME= libft

SRC= $(wildcard *.c)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	ar -crs libft.a $(OBJ) 

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f a.out libft.a libft.so $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

re: fclean all

.PHONY: all clean fclean re
