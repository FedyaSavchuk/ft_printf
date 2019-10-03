/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xxo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:59:08 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/02 22:35:53 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_format_xo(char ns)
{
	if (g_flags->grill)
		ft_putchar('0');
	if (g_flags->grill && ns != 'o')
		ft_putchar(ns);
}

int			print_xxo(unsigned long long int nbr, char ns)
{
	char	*snbr;

	if (!nbr)
		return (0);
	if (ns == 'b')
		snbr = ft_itoa_base(nbr, 2, 'a');
	else
		snbr = ft_itoa_base(nbr, (ns == 'o') ? 8 : 16, (ns == 'X') ? 'A' : 'a');
	if (g_flags->minus)
		print_format_xo(ns);
	else
	{
		if (g_flags->zero)
			print_format_xo(ns);
		ft_putchars((g_flags->zero) ? '0' : ' ', g_flags->min_width -
												 ft_strlen(snbr) - g_flags->grill - (ns != 'o' && g_flags->grill));
		if (!g_flags->zero)
			print_format_xo(ns);
	}
	ft_putstr(snbr);
	if (g_flags->minus)
		ft_putchars(' ', g_flags->min_width - ft_strlen(snbr) -
						 g_flags->grill - (ns != 'o' && g_flags->grill));
	free(snbr);
	return (1);
}
