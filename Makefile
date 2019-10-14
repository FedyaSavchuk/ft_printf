.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror -I./libft/includes/ -I./includes/#-L./libft/ -lft

FILES = convert.c \
      ft_printf.c \
      read_flags.c \
      print_xob.c \
      print_di.c \
      print_tyr.c \
      print_u.c \
      print_s.c \
      print_c.c \
      print_fff.c \
      infin_mult.c 

SRC_PATH = ./src/

SRC = $(addprefix $(SRC_PATH), $(FILES))

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
