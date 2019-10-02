/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:35:46 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 20:35:47 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = -1;
	while (++i < (int)n && s1[i])
		if (s1[i] != s2[i])
			break ;
	if (i == (int)n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
