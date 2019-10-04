/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:17:45 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/29 19:17:48 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <string.h>

// функция очищает флаги
void 	clear_flags(void)
{
	g_flags->zero = 0;
	g_flags->minus = 0;
	g_flags->plus = 0;
	g_flags->grill = 0;
	g_flags->dote = 0;
	g_flags->space = 0;
	g_flags->h = 0;
	g_flags->hh = 0;
	g_flags->l = 0;
	g_flags->ll = 0;
	g_flags->L = 0;
	g_flags->min_width = 0;
	g_flags->cut = 0;
}

// функция записывает флаги в список
char 	read_flags(const char *format, va_list *argv)
{
	int i;
	i = g_iter;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != 'd' && format[i] != 'r'
		   && format[i] != 'i' && format[i] != 'o' && format[i] != 'u' && format[i] != 't' && format[i] != 'y'
		   && format[i] != 'x' && format[i] != 'X' && format[i] != 'f' && format[i] != '\0')
	{
		if (format[i] == ' ')
			g_flags->space = 1;
		else if (format[i] == '-')
			g_flags->minus = 1;
		else if (format[i] == '+')
			g_flags->plus = 1;
		else if (format[i] == '#')
			g_flags->grill = 1;
		else if (format[i] == 'h' && format[i + 1] == 'h')
			g_flags->hh = 1;
		else if (format[i] == 'h')
			g_flags->h = 1;
		else if (format[i] == 'l' && format[i + 1] == 'l')
			g_flags->ll = 1;
		else if (format[i] == 'l')
			g_flags->l = 1;
		else if (format[i] == 'L')
			g_flags->L = 1;
		else if (format[i] == '*')
		{
			if (format[i - 1] == '.')
				g_flags->dote = va_arg(*argv, int);
			else if (format[i - 1] == '0')
				g_flags->zero = va_arg(*argv, int);
			else
			g_flags->min_width = va_arg(*argv, int);
		}
		else if (format[i] <= '9' && format[i] >= '1')
		{
			while (format[i] <= '9' && format[i] >= '0')
			{
				g_flags->min_width = g_flags->min_width * 10 + (format[i] - '0');
				i++;
			}
			i--;
		}
		else if (format[i] == '0')
			g_flags->zero = 1;
		else if (format[i] == '.')
		{
			g_flags->dote = 1;
			i++;
			while (format[i] <= '9' && format[i] >= '0')
			{
				g_flags->cut = g_flags->cut * 10 + (format[i] - '0');
				i++;
			}
			i--;
		}
		else
		{
			clear_flags();
			return (0);
		}
		i++;
	}
	g_iter = i;
	return (format[i]);
}

// функция отправляет флаги и спецификаторы на обработку
int		ft_printf(const char *format, ... )
{
	va_list				argv;
	char 				spec;

	g_iter = 0;
	va_start(argv, format);
	g_flags = (t_flags *)malloc(sizeof(t_flags));
	while (format[g_iter])
	{
		if (format[g_iter] != '%')
			ft_putchar(format[g_iter]);
		if (format[g_iter] == '%' && format[g_iter + 1] == '%')
			ft_putchar(format[++g_iter]);
		else
		{
			g_iter++;
			clear_flags();
			if (!(spec = read_flags(format, &argv)))
				continue ;
			if (spec == 'd' || spec == 'i')
				print_di(convert_d(&argv));
			else if (spec == 'u')
				print_u(convert_u(&argv));
			else if (spec == 'x' || spec == 'X' || spec == 'o' || spec == 'b')
				print_xxo(convert_u(&argv), spec);
			else if (spec == 't')
				print_t(va_arg(argv, char **));
			else if (spec == 's')
				print_s(va_arg(argv, char *));
			else if (spec == 'y')
				print_y(va_arg(argv, char ***));
			else if (spec == 'p' && (g_flags->grill = 1) && !(print_xxo(va_arg(argv, unsigned long int), 'x')))
				ft_putstr("(nill)");
			else if (spec == 'r')
				read_file(va_arg(argv, int));
		}
		g_iter++;
	}
	free(g_flags);
	return (0);
}

int		main(void)
{
	printf("\n----------- TESTS -----------\n");
	int			i = 2147483647;
	long		l = 2147483647;
	long long	ll = 9223372036854775807;
	char		c = 0;
	intmax_t	im = 9223372036854775807;

	long int a = 372036854775200;
	ft_printf("|%ld|", a);
	printf("|%ld|", a);

	printf("\n--------- Check Flags ---------\n");
	printf("g_flags->zero           : %d\n", g_flags->zero);
	printf("g_flags->minus          : %d\n", g_flags->minus);
	printf("g_flags->plus           : %d\n", g_flags->plus);
	printf("g_flags->grill          : %d\n", g_flags->grill);
	printf("g_flags->dote           : %d\n", g_flags->dote);
	printf("g_flags->space          : %d\n", g_flags->space);
	printf("g_flags->h              : %d\n", g_flags->h);
	printf("g_flags->hh             : %d\n", g_flags->hh);
	printf("g_flags->l              : %d\n", g_flags->l);
	printf("g_flags->ll             : %d\n", g_flags->ll);
	printf("g_flags->L              : %d\n", g_flags->L);
	printf("g_flags->min_width      : %d\n", g_flags->min_width);
	printf("------------------------------\n");
	return (0);
}

