/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:30:48 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:30:50 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;
	long long	prev;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i++] == '-'))
		sign = -1;
	while (str[i] != '\0')
	{
		prev = res;
		if ((int)(str[i] - '0') > 9 || (int)(str[i] - '0') < 0)
			return (sign * res);
		res = res * 10 + (int)(str[i] - '0');
		if (res < prev)
			return ((sign == 1) ? -1 : 0);
		i++;
	}
	return ((int)(sign * res));
}
