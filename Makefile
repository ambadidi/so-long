CC = gcc 

NAME = so_long

FLAGS =-g -Wall -Wextra -Werror  -fsanitize=address -g3 -I /usr/local/include

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c parse.c draw.c  moveplayer.c movplayer.c texture.c utils/gnl.c utils/tools.c utils/ft_putnbr.c

INCS = so_long.h



all: $(SRC)
	$(CC) $(FLAGS) $(MLX) $(SRC) -o $(NAME)

$(NAME): all

clean:
	echo all good

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all
