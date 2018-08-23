NAME = fractol
SRC = $(wildcard src/*.c)
CFLAGS = -Wall -Wextra -Werror
SANIFLAGS = -g -fsanitize=address
LIBFTFLAGS = -I include -L src/libft
MLXFLAGS = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(CFILES:.c =.o)

all: $(NAME)

$(NAME): $(SRC) minilibx/libmlx.a
	gcc -o $(NAME) $(CFLAGS) $(MLXFLAGS) $(LIBFTFLAGS) $(SRC) src/libft.a

minilibx/libmlx.a:
	cd src/libft && make -f Makefile
	mv src/libft/libft.a src
	cd minilibx && make

clean:
	cd src/libft && make clean
	rm -rf $(NAME)

fclean:
	cd src/libft && make fclean
	cd minilibx && make clean
	rm -rf src/libft.a

re: fclean $(NAME)

.PHONY : clean fclean re
