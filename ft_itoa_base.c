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

char	*ft_itoa_base(int value, int base, char reg)
{
	int		i;
	int		mult;
	int		power;
	char	*table;
	char	arr[16];

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		arr[i] = reg + i - 10;
		i++;
	}
	i = 0;
	mult = 1;
	table = malloc(sizeof(char) * 34);
	power = 1;
	if (value < 0)
	{
		if (base == 10)
			table[i++] = '-';
		mult = -1;
	}
	if (value != -2147483648)
		while ((value / power) * mult >= base)
			power = power * base;
	else
	{
		power = base;
		while ((value / power * mult) >= base)
		{
			if (value / power * mult == base &&	value % power == 0)
			{
				table[i++] = arr[1];
				value = value - mult * power * base;
			}
			else
				power = power * base;
		}
	}
	while (1)
	{
		table[i++] = arr[(value / power) * mult];
		value = value - power * (value / power);
		power = power / base;
		if (power == 0)
			break ;
	}
	table[i] = '\0';
	return (table);
}
