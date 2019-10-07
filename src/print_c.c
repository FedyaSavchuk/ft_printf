/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:31:10 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/07 22:31:12 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(char c)
{
	if (g_flags->minus)
		ft_putchar(c);
	ft_putchars(' ', g_flags->min_width - 1);
	if (!g_flags->minus)
		ft_putchar(c);
	return (0);
}
