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

int		print_s(char *str, int flag)
{
	int		len;
	char	*s;

	if (!str)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(str);
	len = ft_strlen(s);
	if (g_flags->dote && len > g_flags->cut)
		len = g_flags->cut;
	if (g_flags->minus)
		write(1, s, len);
	ft_putchars(((!flag && (g_flags->zero && !g_flags->minus)) ? '0' : ' ') , g_flags->min_width - len);
	if (!g_flags->minus)
		write(1, s, len);
	g_giter += len;
	ft_strdel(&s);
	return (0);
}
