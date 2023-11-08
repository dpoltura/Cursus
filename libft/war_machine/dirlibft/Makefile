OBJ= $(SRC:%.c=%.o)
CFLAGS= -g -Wall -Werror -Wextra
CC= clang
NAME= libft
SRC= $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	ar -crs libft.a $(OBJ) 

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

re: fclean all	

.PHONY: all clean fclean re
