# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:55:15 by hjo               #+#    #+#              #
#    Updated: 2018/02/20 15:55:17 by hjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libft.a
HEADER	=	../../include
OPTION	=	-c -I $(HEADER)
CFLAGS	=	-Wall -Wextra -Werror
CFILES	=	$(wildcard *.c)
OBJ		=	$(CFILES:.c=.o)

$(NAME):
	gcc $(CFLAGS) $(OPTION) $(CFILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
