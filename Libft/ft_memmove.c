/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:32:43 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:32:45 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*dest2;
	unsigned char	*src2;

	i = -1;
	if (!dest && !src)
		return (0);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (src < dest)
		while (n--)
			dest2[n] = src2[n];
	else
		while (++i < (int)n)
			dest2[i] = src2[i];
	return (dest);
}
