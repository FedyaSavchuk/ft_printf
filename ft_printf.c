#include "printf.h"


// функция очищает флаги
void 	clear_flags(void)
{
	g_flags->nul = 0;
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
char 	read_flags(const char *format, int i)
{

	g_flags = (t_flags *)malloc(sizeof(t_flags *) * 1);
	g_flags->min_width = 0;
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
		else if (format[i] == '.')
			g_flags->dote = 1;
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
//		else if (format[i] == '0')
//		{
//
//		}
//			g_flags->nul = 1;
		else
		{
			// записать число и если не будет равно одному из спецификаторов - войти в елсе
			while (format[i] <= '9' && format[i] >= '0')
			{
				g_flags->min_width = g_flags->min_width * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] == 'd'
				|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == 'f' || format[i] != '\0')
			{
				g_flags->format[i] = 1;
				break ;
			}

			clear_flags();
			return (0);
		}
		i++;
	}
	return (format[i]);
}



// функция отправляет флаги и спецификаторы на обработку
int		ft_printf(const char *format, ... )
{
    va_list				argv;
    int					i;
    char 				spec;

    //count = read_format(format);
    i = 0;
    g_flags = (t_flags *)malloc(sizeof(t_flags *) * 1);
	va_start(argv, format);
	while (format[i])
    {
		if (format[i] != '%')
			ft_putchar(format[i]);
	    else if (format[i] == '%' && format[i + 1] == '%')
		{
	    	i++;
			ft_putchar(format[i]);
		}
	    else
        {
	        i++;
			if (!(spec = read_flags(format, i)))
				continue ;
	        if (spec == 'd' || spec == 'i')
                ft_putnbr(va_arg(argv, int));
	        if (spec == 'o')
				// Функция Витали(перевод в 8-ую систему);
	        if (spec == 'u')
				ft_putnbr(va_arg(argv, unsigned int));
			if (spec == 'x' || format[i] == 'X')
				// Функция Витали (перевод в 16-ую систему);
				// Функция добавления флагов
			clear_flags();
        }
	    i++;

    }
	return (0);
}

int     main(void)
{
	char a;
    //ft_printf("H %5ello %d \n %d", 5);
    a = read_flags("H %02 d %d \n %d", 3);
    ft_putnbr(g_flags->min_width);
    write(1, &a, 1);
    return (0);
}


