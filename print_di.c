/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:35:33 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/02 22:35:36 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_di(long long int nbr)
{
	char	*snbr;
	int		c;

	snbr = ft_itoa_base(nbr, 10, 'a');
	c = g_flags->min_width - ft_strlen(snbr) -
		((g_flags->plus || g_flags->space) && nbr >= 0) -
		((g_flags->cut > ft_strlen(snbr) ? g_flags->cut - ft_strlen((nbr < 0) ? &snbr[1] : snbr) : 0));
	if (g_flags->space && !g_flags->plus && nbr >= 0)
		ft_putchar(' ');
	if (g_flags->plus && nbr >= 0)
		ft_putchar('+');
	if (g_flags->minus)
		ft_putstr(snbr);
	ft_putchars(' ', (g_flags->zero && !g_flags->minus) ? 0 : c);
	if(!g_flags->minus && nbr < 0)
		ft_putchar('-');
	ft_putchars('0', (g_flags->zero && !g_flags->minus) ? c : 0);
	ft_putchars('0', g_flags->cut - ft_strlen((nbr < 0) ? &snbr[1] : snbr));
	if (!g_flags->minus)
		ft_putstr((nbr < 0) ? &snbr[1] : snbr);
	free(snbr);
	return (0);
}
