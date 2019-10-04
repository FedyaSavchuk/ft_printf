/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:37:45 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:37:46 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	if (!(s) || !(f) || !(ptr = ft_strnew(ft_strlen(s))))
		return (0);
	i = -1;
	while (s[++i] != '\0')
		ptr[i] = f(s[i]);
	return (ptr);
}
