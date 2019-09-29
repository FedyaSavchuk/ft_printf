
#include "printf.h"

int     print_di(long long int nbr)
{
	char *snbr;
	int c;
	snbr = ft_itoa_base(nbr, 10, 'a');
	c = g_flags->min_width - ft_strlen(snbr) - g_flags->plus;
	if(c <= 0 && g_flags->space && !g_flags->plus && nbr >= 0)
		ft_putchar(' ');
	if(g_flags->minus)
	{
		if(g_flags->plus && nbr >= 0)
			ft_putchar('+');
		ft_putstr(snbr);
	}
	ft_putchars((g_flags->zero && !g_flags->minus) ? '0' : ' ', c);
	if(!g_flags->minus)
	{
		if(g_flags->plus && nbr >= 0)
			ft_putchar('+');
		ft_putstr(snbr);
	}
	return (0);
}
