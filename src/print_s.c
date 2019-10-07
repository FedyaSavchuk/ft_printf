/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:43:48 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/07 22:43:50 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(char *str)
{
	int len;

	if (!str)
	{
		ft_putstr("(null)");
		return (0);
	}
	len = ft_strlen(str);
	if (g_flags->dote && len > g_flags->cut)
		len = g_flags->cut;
	if (g_flags->minus)
		write(1, str, len);
	ft_putchars(' ', g_flags->min_width - len);
	if (!g_flags->minus)
		write(1, str, len);
	g_giter += len;
	return (0);
}
