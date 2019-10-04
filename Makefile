.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror -L./libft/ -lft

SRC = convert.c ft_printf.c print_Xxo.c print_di.c print_tyr.c print_u.c print_s.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o printf.o $(OBJ)

$(LIBFT):
	make -C ./libft
	make -C ./libft clean

clean:
	rm $(OBJ)

fclean: clean
	make -C ./Libft fclean

re: fclean all