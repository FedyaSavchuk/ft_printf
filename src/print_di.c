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

#include "ft_printf.h"

int	print_di(long long int nbr)
{
	char	*snbr;
	int		c;

	snbr = ft_itoa_base(nbr, 10, 'a');
	c = g_flags->min_width - ft_strlen(snbr) -
		((g_flags->plus || g_flags->space) && nbr >= 0);
	if (g_flags->space && !g_flags->plus && nbr >= 0)
		ft_putchar(' ');
	if (g_flags->plus && nbr >= 0)
		ft_putchar('+');
	if (g_flags->minus)
		ft_putstr(snbr);
	if(!g_flags->minus && g_flags->zero && nbr < 0)
		ft_putchar('-');
	ft_putchars((g_flags->zero && !g_flags->minus) ? '0' : ' ', c);
	if (!g_flags->minus)
		ft_putstr((g_flags->zero && nbr < 0) ? &snbr[1] : snbr);
	free(snbr);
	return (0);
}
