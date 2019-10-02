/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:09:55 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 13:15:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_base(long long int value, int base, char reg)
{
	int		i;
	int		mult;
	int		power;
	char	*table;
	char	arr[16];

	i = -1;
	while (++i < 16)
		arr[i] = (i < 10) ? i + '0' : reg + i - 10;
	i = 0;
	mult = (value < 0) ? -1 : 1;
	table = malloc(sizeof(char) * 66);
	power = 1;
	(value < 0 && base == 10) ? table[i++] = '-' : 0;
	while ((value / power) * mult >= base)
		power *= base;
	while (0 == 0)
	{
		table[i++] = arr[(value / power) * mult];
		value -= power * (value / power);
		if (!(power /= base))
			break ;
	}
	table[i] = '\0';
	return (table);
}
