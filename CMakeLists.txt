cmake_minimum_required(VERSION 3.14)
project(Print_f C)

set(CMAKE_C_STANDARD 11)

include_directories(Libft)

add_executable(Print_f
        printf.h ft_printf.c Libft/ft_putchar.c Libft/ft_putnbr.c)
