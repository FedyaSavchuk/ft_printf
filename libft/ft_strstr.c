/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:37:20 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:37:21 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			while (to_find[j] != '\0' && to_find[j] == str[i + j])
				j++;
			if (to_find[j] == '\0')
				return ((char*)&str[i]);
		}
		j = 0;
	}
	return (0);
}
