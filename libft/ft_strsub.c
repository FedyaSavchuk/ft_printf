/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:38:36 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:38:37 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str1;
	char			*str2;
	unsigned int	i;

	if (len + 1 < len)
		return (NULL);
	str1 = NULL;
	str2 = NULL;
	i = 0;
	if (s)
	{
		str1 = (char*)malloc(sizeof(char) * (len + 1));
		str2 = str1;
		if (!(str1))
			return (0);
		while (i < len)
			str1[i++] = (char)s[start++];
		str1[i] = '\0';
	}
	return (str2);
}
