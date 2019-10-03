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


long long int convert_d(va_list *argv)
{
	if (g_flags->h)
		return ((long long int)(short int)va_arg(*argv, int));
	if (g_flags->hh)
		return ((long long int)(char)va_arg(*argv, int));
	if (g_flags->l)
		return ((long long int)va_arg(*argv, long int));
	if (g_flags->ll)
		return ((long long int)va_arg(*argv, long long int));
	return (va_arg(*argv, int));
}


unsigned long long int convert_u(va_list *argv)
{
	if (g_flags->h)
		return ((unsigned long long int)(unsigned short int)va_arg(*argv, unsigned int));
	if (g_flags->hh)
		return ((unsigned long long int)(unsigned char)va_arg(*argv, unsigned int));
	if (g_flags->l)
		return ((unsigned long long int)va_arg(*argv, unsigned long int));
	if (g_flags->ll)
		return ((unsigned long long int)va_arg(*argv, unsigned long long int));
	return (va_arg(*argv, unsigned int));
}

long double convert_f(va_list *argv)
{
	if (g_flags->l)
		return ((long double)va_arg(*argv, double));
	if (g_flags->L)
		return ((long double)va_arg(*argv, long double));
	return ((long double)(float)va_arg(*argv, double));
}

// функция записывает флаги в список
char 	read_flags(const char *format)
{
	int i;

	clear_flags();
	i = g_iter;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != 'd'
	&& format[i] != 'i' && format[i] != 'o' && format[i] != 'u' && format[i] != 't'
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
		else if (format[i] == 'h' && format[i++] == 'h')
			g_flags->hh = 1;
		else if (format[i] == 'h')
			g_flags->h = 1;
		else if (format[i] == 'l')
			g_flags->l = 1;
		else if (format[i] == 'l' && format[i++] == 'l')
			g_flags->ll = 1;
		else if (format[i] == 'L')
			g_flags->L = 1;
		else if (format[i] <= '9' && format[i] >= '1')
		{
			while (format[i] <= '9' && format[i] >= '0')
				g_flags->min_width = g_flags->min_width * 10 + (format[i++] - '0');
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
    	clear_flags();
		if (format[g_iter] != '%')
			ft_putchar(format[g_iter]);
		if (format[g_iter] == '%' && format[g_iter + 1] == '%')
			ft_putchar(format[++g_iter]);
		else
        {
			g_iter++;
			if (!(spec = read_flags(format)))
				continue ;
	        else if (spec == 'd' || spec == 'i')
				print_di(convert_d(&argv));
	        else if (spec == 'u')
				print_di(convert_u(&argv));
			//else if (spec == 'f')
			//	print_ld(convert_f(&argv));
			else if (spec == 'x' || spec == 'X' || spec == 'o')
				print_xxo(convert_u(&argv), spec);
			else if (spec == 't')
				print_t(va_arg(argv, char **));
			//if (spec == 'y')
			//	print_y(va_arg(argv, char ***));
			else if (spec == 'p' && !(print_xxo(va_arg(argv, unsigned long int), 'x')))
				ft_putstr("(nill)");
		}
		g_iter++;

	}
	return (0);
}

int		main(void)
{
	
	long a = 34567891234567890;
	char *str;
	printf("\n----------- TESTS -----------\n");
	ft_printf("|%ld|", a);
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


