/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:33:44 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:33:46 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] == (char)c)
			return ((char*)&s[i]);
	if (!c)
		return ((char*)&s[i]);
	return (NULL);
}
