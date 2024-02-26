# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:31:40 by dpoltura          #+#    #+#              #
#    Updated: 2024/02/26 13:38:05 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SERVER_SRC =	server.c \
				ft_strjoin.c \
				ft_calloc.c

CLIENT_SRC =	client.c \
				ft_strjoin.c

SERVER_OBJ = $(SERVER_SRC:%.c=%.o)
CLIENT_OBJ = $(CLIENT_SRC:%.c=%.o)

INCLUDE = -L ft_printf -lftprintf 
FT_PRINTF = libftprintf.a

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(INCLUDE)

$(SERVER): $(CLIENT) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) $(INCLUDE)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re