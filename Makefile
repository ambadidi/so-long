CC = gcc 

NAME = so_long

FLAGS = -Wall -Wextra -Werror -I /usr/local/include

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c parsing_funct.c texture.c moveplayer.c printmv.c rendering.c free.c error_handling.c utils/gnl.c utils/tools.c utils/ft_putnbr.c utils/tools2.c

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
