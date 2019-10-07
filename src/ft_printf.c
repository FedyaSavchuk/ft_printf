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

#include "ft_printf.h"

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
            {
                g_flags->cut = va_arg(*argv, int);
                g_flags->dote = (g_flags->cut >= 0) ? g_flags->dote : 0;
                g_flags->cut = (g_flags->cut >= 0) ? g_flags->cut : 0;
            }
            else if(format[i + 1] <= '9' && format[i + 1] >= '0')
                va_arg(*argv, int);
            else
            {
                g_flags->min_width = va_arg(*argv, int);
                g_flags->minus = (g_flags->min_width < 0) ? 1 : 0;
                g_flags->min_width = ft_abs(g_flags->min_width);
            }
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

int check_double_percents(const char *format)
{
	int i = 0;

	if(format[g_iter] == '%')
	{
		i++;
		while(format[g_iter + i] == ' ' || format[g_iter + i] == '.' || format[g_iter + i] == '-' || (format[g_iter + i] >= '0' && format[g_iter + i] <= '9'))
			i++;
		if (format[g_iter + i] == '%')
		{
			g_iter += i;
			i = g_iter;
			if(i > 1 && format[i - 1] >= '0' && format[i - 1] <= '9')
			{
				i--;
				while((format[i] >= '0' && format[i] <= '9'))
					i--;
				if(format[i] == '%')
					i++;
				i = ft_atoi(&format[i]);
				if(i > 0)
					ft_putchars(' ', i - 1);
				else
				{
					ft_putchar('%');
					ft_putchars(' ', i * -1 - 1);
					return(0);
				}
			}
			
			return(1);
		}
	}
	return (0);
}

// функция отправляет флаги и спецификаторы на обработку
int		ft_printf(const char *format, ...)
{
	va_list				argv;
	char 				spec;

	g_iter = 0;
	g_giter = 0;
	va_start(argv, format);
	g_flags = (t_flags *)malloc(sizeof(t_flags));
	while (format[g_iter])
	{
		if (format[g_iter] != '%')
			ft_putchar(format[g_iter]);
		else if (check_double_percents(format))
			ft_putchar(format[g_iter]);
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
			else if (spec == 'c')
				print_c(va_arg(argv, int));
			else if (spec == 'y')
				print_y(va_arg(argv, char ***));
			else if (spec == 'f')
				print_lf(convert_f(&argv));
			else if (spec == 'p')
				print_xxo(va_arg(argv, unsigned long int), 'p');
		}
		g_iter++;
	}
	free(g_flags);
	va_end(argv);
	return (g_giter);
}

//int		main(void)
//{
////	printf("\n----------- TESTS -----------\n");
//
//	ft_printf("This is a simple test.");
//	//printf("|Abcdef|", a);
//
////	printf("\n--------- Check Flags ---------\n");
////	printf("g_flags->zero           : %d\n", g_flags->zero);
////	printf("g_flags->minus          : %d\n", g_flags->minus);
////	printf("g_flags->plus           : %d\n", g_flags->plus);
////	printf("g_flags->grill          : %d\n", g_flags->grill);
////	printf("g_flags->dote           : %d\n", g_flags->dote);
////	printf("g_flags->space          : %d\n", g_flags->space);
////	printf("g_flags->h              : %d\n", g_flags->h);
////	printf("g_flags->hh             : %d\n", g_flags->hh);
////	printf("g_flags->l              : %d\n", g_flags->l);
////	printf("g_flags->ll             : %d\n", g_flags->ll);
////	printf("g_flags->L              : %d\n", g_flags->L);
////	printf("g_flags->min_width      : %d\n", g_flags->min_width);
////	printf("------------------------------\n");
//	return (0);
//}

