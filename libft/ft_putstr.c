/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:36:05 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:36:06 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_printf.h"

void	ft_putstr(const char *s)
{
	size_t len;

	len = ft_strlen(s);
	g_giter += len;
	if (s)
		write(1, s, len);
}
