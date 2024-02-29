# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:31:40 by dpoltura          #+#    #+#              #
#    Updated: 2024/02/29 23:55:44 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SERVER_BONUS_SRC =	server_bonus.c \
					ft_strjoin.c \
					ft_calloc.c

CLIENT_BONUS_SRC =	client_bonus.c \
					ft_strjoin.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:%.c=%.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:%.c=%.o)

INCLUDE = -L ft_printf -lftprintf 
FT_PRINTF = libftprintf.a

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS) $(INCLUDE)

$(SERVER_BONUS): $(CLIENT_BONUS) $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS) $(INCLUDE)

clean:
	rm -f $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re