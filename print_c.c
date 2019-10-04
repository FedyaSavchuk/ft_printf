#include "printf.h"

void	ft_putchars(char c, int i)
{
	while (i-- > 0)
		ft_putchar(c);
}

int		print_c(char c)
{
	if(g_flags->minus)
		ft_putchar(c);
	ft_putchars(' ', g_flags->minwidth - 1);
	if(!g_flags->minus)
		ft_putchar(c);
	return (0);
}