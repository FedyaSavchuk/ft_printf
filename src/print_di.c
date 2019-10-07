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

char	*add_cut_di(char *snbr)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = NULL) && ft_strlen(snbr) <= (unsigned long)g_flags->cut)
	{
		tmp = ft_strnew(g_flags->cut + (g_flags->plus || (snbr)[0] == '-'));
		if ((snbr)[0] != '-')
		{
			if (g_flags->plus--)
				tmp[0] = '+';
			while (i++ < (int)(g_flags->cut - ft_strlen(snbr)))
				ft_strcat(tmp, "0");
			ft_strcat(tmp, snbr);
		}
		else
		{
			tmp[0] = '-';
			while (i++ < (int)(g_flags->cut - ft_strlen(snbr) + 1))
				ft_strcat(tmp, "0");
			ft_strcat(tmp, &snbr[1]);
		}
		free(snbr);
	}
	return ((tmp) ? tmp : snbr);
}

int		print_di(long long int nbr)
{
	char	*snbr;
	int		c;

	snbr = add_cut_di(ft_itoa_base(nbr, 10, 'a'));
	c = g_flags->min_width - ft_strlen(snbr) -
		((g_flags->plus > 0 || g_flags->space) && nbr >= 0);
	if (!nbr && g_flags->dote && !g_flags->cut)
		ft_putchars((g_flags->zero && !g_flags->minus && !g_flags->dote)
			? '0' : ' ', c + 1);
	if (!nbr && g_flags->dote && !g_flags->cut)
		return (0);
	if (g_flags->space && !(g_flags->plus > 0) && nbr >= 0)
		ft_putchar(' ');
	if (g_flags->plus > 0 && nbr >= 0)
		ft_putchar('+');
	if (g_flags->minus)
		ft_putstr(snbr);
	if (!g_flags->minus && g_flags->zero && nbr < 0)
		ft_putchar('-');
	ft_putchars((g_flags->zero && !g_flags->minus && !g_flags->dote)
		? '0' : ' ', c);
	if (!g_flags->minus)
		ft_putstr((g_flags->zero && nbr < 0) ? &snbr[1] : snbr);
	free(snbr);
	return (0);
}
