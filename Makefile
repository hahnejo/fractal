NAME = fractol
SRC = $(wildcard src/*.c)
CFLAGS = -Wall -Wextra -Werror
LIBFTFLAGS = -I include -L libft
OBJ = $(CFILES:.c =.o)

ifeq ($(shell uname), Darwin)
	OS = MAC
	MLXDIR = minilibx
	MLXFLAGS = -L minilibx -L /usr/X11/lib  -framework OpenGL -framework CoreFoundation -framework Appkit -lft -lmlx
else
	OS = LINUX
	MLXDIR = minilibx_linux
	MLXFLAGS = -L minilibx_linux -lft -lmlx -lX11 -lXext -lm
endif

all: $(NAME)

$(NAME): $(SRC) $(MLXDIR)/libmlx.a
	gcc -o $(NAME) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) $(SRC)

$(MLXDIR)/libmlx.a:
	cd libft && make -f Makefile
	cd minilibx && make

clean:
	cd src/libft && make clean
	rm -rf $(NAME)

fclean:
	cd libft && make fclean
	cd minilibx && make clean
	rm -rf libft/libft.a
	rm fractol

re: fclean

.PHONY : clean fclean re
