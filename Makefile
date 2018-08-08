NAME = fractol
SRC = $(wildcard *.c)
OPTION = minilibx/
CFLAGS = -Wall -Wextra -Werror -I include -L src/libft \
-I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(CFILES:.c =.o)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a src
	cd minilibx && Makefile
	gcc -o $(NAME) $(CFLAGS) $(SRC) src/libft.a

clean:
	cd src/libft && make fclean

fclean:
	cd src/libft && make fclean
	cd minilibx && make clean
	rm -rf $(NAME)
	rm -rf src/libft.a

re: fclean $(NAME)

.PHONY : clean fclean re
