.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror -I./libft/includes/ -I./includes/#-L./libft/ -lft

SRC = src/convert.c src/ft_printf.c src/print_Xxo.c src/print_di.c src/print_tyr.c src/print_u.c src/print_s.c src/print_f.c

SRC_PATH = ./src/

LIBFT = ./libft/libft.a

LIBFT_OBJ = ./libft/ft_*.o

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	make -C ./Libft fclean
	rm -f $(NAME)

re: fclean all