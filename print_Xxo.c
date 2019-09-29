/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xxo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:59:08 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/28 21:59:10 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchars(char c, int i)
{
	while (i-- > 0)
		ft_putchar(c);
}

void	print_format_xo(char ns)
{
	if (g_flags->grill)
		ft_putchar('0');
	if (g_flags->grill && ns != 'o')
		ft_putchar(ns);
}

int	convert_xo(int nbr)
{
	if (g_flags->h)
		nbr = (short int)nbr;
	if (g_flags->hh)
		nbr = (char)nbr;
	if (g_flags->l)
		nbr = (long int)nbr;
	if (g_flags->ll)
		nbr = (long long int)nbr;
	return (nbr);
}

int		print_xxo(int nbr, char ns)
{
	char *snbr;

	nbr = convert_xo(nbr);
	snbr = ft_itoa_base(nbr, (ns == 'o') ? 8 : 16, (ns == 'X') ? 'A' : 'a');
	if (g_flags->minus || (g_flags->min_width && g_flags->zero))
	{
		print_format_xo(ns);
		if (!g_flags->minus)
			ft_putchars('0', g_flags->min_width - ft_strlen(snbr) -
				g_flags->grill - ((ns == 'o') ? 0 : 1));
	}
	else if (g_flags->min_width)
	{
		ft_putchars(' ', g_flags->min_width - ft_strlen(snbr) -
			g_flags->grill - ((ns == 'o') ? 0 : 1));
		if (g_flags->grill)
			ft_putchar('0');
		print_format_xo(ns);
	}
	ft_putstr(snbr);
	return (0);
}