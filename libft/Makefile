NAME	=	libft.a
HEADER	=	include
OPTION	=	-c -I $(HEADER)
CFLAGS	=	-Wall -Wextra -Werror
CFILES	=	$(wildcard src/*.c)
OBJ		=	$(patsubst src/%.c, obj/%.o, $(CFILES))

all: $(NAME)

$(NAME): obj $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj:
	mkdir obj

obj/%.o: src/%.c
	gcc $(CFLAGS) $(OPTION) -c -o $@ $<

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all re clean fclean
