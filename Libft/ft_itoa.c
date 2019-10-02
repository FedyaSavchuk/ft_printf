/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:31:50 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:31:53 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int value)
{
	int		len;
	int		digit;
	char	*nbr;
	int		sign;
	long	valuel;

	valuel = value;
	digit = valuel;
	len = 1;
	sign = ((valuel < 0) ? 1 : 0);
	while ((digit /= 10) != 0)
		len++;
	if (!(nbr = (char*)ft_memalloc(sizeof(char) * (len + 1 + sign))))
		return (0);
	nbr[0] = '-';
	valuel *= ((sign) ? -1 : 1);
	while (len > 0)
	{
		digit = valuel % 10;
		nbr[--len + sign] = digit + '0';
		valuel = valuel / 10;
	}
	return (nbr);
}
