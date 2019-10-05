/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:09:55 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 13:15:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long value, int base, char reg)
{
	char				*str;
	int					size;
	char				*tab;
	int					flag;
	unsigned long long	tmp;

	flag = 0;
	size = 0;
	tab = (reg >= 'A' && reg <= 'Z') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size += flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = tab[ft_abs(value % base)];
		value /= base;
	}
	return (str);
}
