#include "printf.h"

// функция записывает флаги в список
void 	read_flags(const char *format, int i)
{
	if (format[i] == ' ')
		g_flags->null = 1;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != 'd'
	&& format[i] != 'i' && format[i] != 'o' && format[i] != 'u'
	&& format[i] != 'x' && format[i] != 'X' && format[i] != 'f' && format[i])
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

		else if (format[i] == '0')
		{
			if (format[i] <= 9)
		}
			g_flags->null = 1;
		else
			clear_flags();
		i++;
	}
	// если что-то пойдет не так - чистим все флаги
	// определить невалидный ввод
}

// функция очищает флаги
void 	clear_flags(void)
{
	g_flags->null = 0;
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

// функция отправляет флаги и спецификаторы на обработку
int		ft_printf(const char *format, ... )
{
    va_list				argv;
    int					i;

    //count = read_format(format);
    i = 0;
    g_flags = (t_flags *)malloc(sizeof(t_flags *) * 1);
	va_start(argv, format);
	while (format[i])
    {
	    if (format[i] != '%' || (format[i] == '%' && format[i++] != '%'))
	        ft_putchar(format[i]);
	    else
        {
	        i++;
			read_flags(format, i);
	        if (format[i] == 'd' || format[i] == 'i')
                ft_putnbr(va_arg(argv, int));
	        if (format[i] == 'o')
				// Функция Витали(перевод в 8-ую систему);
	        if (format[i] == 'u')
				ft_putnbr(va_arg(argv, unsigned int));
			if (format[i] == 'x' || format[i] == 'X')
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
    ft_printf("H %5ello %d \n %d", 5);
    return (0);
}


