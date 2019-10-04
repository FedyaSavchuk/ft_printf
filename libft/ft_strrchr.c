/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:37:06 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:37:07 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = s;
		s++;
	}
	if (*s == c)
		ptr = s;
	return ((char *)ptr);
}
