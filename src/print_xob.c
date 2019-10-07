/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xxo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:59:08 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/02 22:35:53 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format_xo(char ns, int nbr)
{
	if (ns == 'o' && g_flags->cut)
		return ;
	if (g_flags->grill && (nbr || ns == 'p'))
		ft_putchar('0');
	if (g_flags->grill && ns != 'o' && (nbr || ns == 'p'))
		ft_putchar((ns == 'p') ? 'x' : ns);
}

int			get_len1(char *snbr)
{
	if (!(snbr[0] == '0' && !snbr[1]) || !g_flags->dote)
		return (ft_strlen(snbr));
	return (0);
}

void		add_cut(char **snbr)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strlen(*snbr) < (unsigned long)g_flags->cut)
	{
		tmp = ft_strnew(g_flags->cut);
		while (i++ < (int)(g_flags->cut - ft_strlen(*snbr)))
			ft_strcat(tmp, "0");
		ft_strcat(tmp, *snbr);
		free(*snbr);
		*snbr = tmp;
	}
}

int			kost(char ns)
{
	return (!(g_flags->dote && !g_flags->cut) ||
		(g_flags->grill && ns == 'o' && !g_flags->min_width));
}

int			print_xxo(unsigned long long int nbr, char ns)
{
	char	*snbr;

	g_flags->grill = (ns == 'p') ? 1 : g_flags->grill;
	if (ns == 'b')
		snbr = ft_uitoa_base(nbr, 2, 'a');
	else
		snbr = ft_uitoa_base(nbr, (ns == 'o') ? 8 : 16, ns);
	add_cut(&snbr);
	if (g_flags->minus)
		print_format_xo(ns, nbr);
	else
	{
		if (g_flags->zero)
			print_format_xo(ns, nbr);
		ft_putchars((g_flags->zero) ? '0' : ' ', g_flags->min_width -
		get_len1(snbr) - g_flags->grill - (ns != 'o' && g_flags->grill));
		if (!g_flags->zero)
			print_format_xo(ns, nbr);
	}
	ft_putstr(kost(ns) ? snbr : 0);
	if (g_flags->minus)
		ft_putchars(' ', g_flags->min_width - ft_strlen(snbr) -
		g_flags->grill - (ns != 'o' && g_flags->grill));
	free(snbr);
	return (1);
}
