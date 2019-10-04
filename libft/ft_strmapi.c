/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:37:53 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:37:54 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	if (!(s) || !(f) || !(ptr = ft_strnew(ft_strlen(s))))
		return (0);
	i = -1;
	while (s[++i] != '\0')
		ptr[i] = f(i, s[i]);
	return (ptr);
}
