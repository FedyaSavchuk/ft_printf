/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:35:43 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/02 22:35:45 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned long long int nbr)
{
	char	*snbr;
	int		c;

	snbr = ft_uitoa_base((long long int)nbr, 10, 'a');
	add_cut(&snbr);
	c = g_flags->min_width - ft_strlen(snbr);
	if (g_flags->minus)
		ft_putstr(snbr);
	ft_putchars((g_flags->zero && !g_flags->minus) ? '0' : ' ', c);
	if (!g_flags->minus)
		ft_putstr(snbr);
	free(snbr);
	return (0);
}