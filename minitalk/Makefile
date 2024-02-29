# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:31:40 by dpoltura          #+#    #+#              #
#    Updated: 2024/03/01 00:26:32 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SERVER_SRC = 	server.c \
				ft_strjoin.c \
				ft_calloc.c
SERVER_BONUS_SRC =	server_bonus.c \
					ft_strjoin.c \
					ft_calloc.c

CLIENT_SRC =	client.c \
				ft_strjoin.c
CLIENT_BONUS_SRC =	client_bonus.c \
					ft_strjoin.c

SERVER_OBJ = $(SERVER_SRC:%.c=%.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:%.c=%.o)

CLIENT_OBJ = $(CLIENT_SRC:%.c=%.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:%.c=%.o)

INCLUDE = -L ft_printf -lftprintf 
FT_PRINTF = libftprintf.a

SERVER = server
SERVER_BONUS = server_bonus

CLIENT = client
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(INCLUDE)

$(SERVER): $(CLIENT) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) $(INCLUDE)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS) $(INCLUDE)

$(SERVER_BONUS): $(CLIENT_BONUS) $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS) $(INCLUDE)

clean:
	rm -f $(SERVER_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_OBJ) $(CLIENT_BONUS_OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all bonus clean fclean re