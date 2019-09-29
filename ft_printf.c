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
}


// функция записывает флаги в список
char 	read_flags(const char *format)
{
	int i;
	i = g_iter;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != 'd'
	&& format[i] != 'i' && format[i] != 'o' && format[i] != 'u'
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
			{
				g_flags->min_width = g_flags->min_width * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] == 'd'
				|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == 'f' || format[i] != '\0')
				break ;
			clear_flags();
			return (0);
		}
		else if (format[i] == '0')
		{
			// записать число и если не будет равно одному из спецификаторов - войти в елсе
			while (format[i] <= '9' && format[i] >= '0')
			{
				g_flags->zero = g_flags->zero * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] == 'd'
				|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == 'f')
				break ;
			i--;
		}
		else if (format[i] == '.')
		{
			i++;
			while (format[i] <= '9' && format[i] >= '0')
			{
				g_flags->dote = g_flags->dote * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] == 'd'
				|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == 'f' || format[i] != '\0')
				break ;
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
	g_flags = (t_flags *)malloc(sizeof(t_flags *) * 1);
	while (format[g_iter])
    {
		if (format[g_iter] != '%')
			ft_putchar(format[g_iter]);
	    else if (format[g_iter] == '%' && format[g_iter + 1] == '%')
		{
			g_iter++;
			ft_putchar(format[g_iter]);
		}
	    else
        {
			g_iter++;
			clear_flags();
			if (!(spec = read_flags(format)))
				continue ;
	        if (spec == 'd' || spec == 'i')
                ft_putnbr(va_arg(argv, int)); //print_d
	        if (spec == 'o')
				// Функция Витали(перевод в 8-ую систему);
	        if (spec == 'u')
				ft_putnbr(va_arg(argv, unsigned int));
			if (spec == 'x' || spec == 'X' || spec == 'o')
				print_xxo(va_arg(argv, unsigned int), spec);

        }
		g_iter++;

    }
	return (0);
}

int     main(void)
{
	char a;
	printf("\n----------- TESTS -----------\n");
    ft_printf("%o", 30);
	//printf("|%0.d| \n", 5);
//    a = read_flags("H %02d %d \n %d", 3);
    write(1, &a, 1);
	printf("\n--------- Check Flags ---------\n");
	printf("g_flags->zero   : %d\n", g_flags->zero);
	printf("g_flags->minus  : %d\n", g_flags->minus);
	printf("g_flags->plus   : %d\n", g_flags->plus);
	printf("g_flags->grill  : %d\n", g_flags->grill);
	printf("g_flags->dote   : %d\n", g_flags->dote);
	printf("g_flags->space  : %d\n", g_flags->space);
	printf("g_flags->h      : %d\n", g_flags->h);
	printf("g_flags->hh     : %d\n", g_flags->hh);
	printf("g_flags->l      : %d\n", g_flags->l);
	printf("g_flags->ll     : %d\n", g_flags->ll);
	printf("g_flags->L      : %d\n", g_flags->L);
	printf("------------------------------\n");
    return (0);
}


