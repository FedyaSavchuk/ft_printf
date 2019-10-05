.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror -I./libft/includes #-L./libft/ -lft

SRC = convert.c ft_printf.c print_Xxo.c print_di.c print_tyr.c print_u.c print_s.c print_f.c

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
	gcc -c $(FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	make -C ./Libft fclean
	rm -f $(NAME)

re: fclean all