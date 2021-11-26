CC = gcc 

NAME = so_long

FLAGS = -Wall -Wextra -Werror -I /usr/local/include

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c parse.c draw.c  moveplayer.c movplayer.c texture.c utils/gnl.c utils/tools.c utils/ft_putnbr.c

INCS = so_long.h

OBJ = $(SRC:.c=.o)
SRCS = $(addprefix ./, $(SRC))

all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)

clean:
	@echo no obj files.

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all
