# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pparalax <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 16:59:28 by pparalax          #+#    #+#              #
#    Updated: 2019/09/06 16:59:33 by pparalax         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a
CFLAGS		= -Wall -Wextra -I./includes -c
FILES		= *.c
OBJ	= *.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc *.o -I.libft/includes/libft.h -L./libft -lft -o $(NAME)

$(OBJ):
	gcc $(CFLAGS) $(FILES) -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
