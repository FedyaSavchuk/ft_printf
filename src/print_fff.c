/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:49:28 by pmila             #+#    #+#             */
/*   Updated: 2019/10/14 15:37:19 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_printf.h"
#define LD long double
#define LL unsigned long long
#define MAX_POWER_OF_LDBL 16383
#define MAX_LEN 4096

t_un		g_u;

void		print_res(char *result, char **str)
{
	if (*str)
		free(*str);
	if (result[0] == '0' && result[1] != '.')
		result++;
	*str = ft_strdup(result);
}

void		print_num(char **str, int degr)
{
	char	*result;
	int		i;
	int		k;
	int		j;

	i = ft_strlen((*str));
	i -= degr;
	result = ft_strnew((i > 0 ? i : 1) + g_flags->cut + 3);
	j = 0;
	k = 0;
	result[j++] = '0';
	if (g_flags->dote == 1 && g_flags->cut == 0)
		handle_integer(&result, i, (*str));
	else
	{
		if (i <= 0)
		{
			result[j++] = '0';
			result[j++] = '.';
			while (i++ < 0 && g_flags->cut-- > 1)
				result[j++] = '0';
			while ((*str)[k] != '\0' && g_flags->cut-- > 1)
				result[j++] = (*str)[k++];
		}
		else
		{
			while (i-- > 0 && (*str)[k] != '\0')
				result[j++] = (*str)[k++];
			result[j++] = '.';
			while ((*str)[k] != '\0' && g_flags->cut-- > 1)
				result[j++] = (*str)[k++];
			i += 2;
		}
		if (!(*str)[k])
			while (g_flags->cut-- > 0)
				result[j++] = '0';
		else if (i == 0)
			result[j] = '0' + ((*str)[0] >= '5' ? 1 : 0);
		else if (i < 0)
			result[j] = '0';
		else
			result[j] = (*str)[k] + round_last((*str), k);
		check_round(&result, j);
		result[++j] = '\0';
	}
	print_res(result, str);
	free(result);
}

void		print_f(char **str)
{
	t_ld		*l_info;
	int			i;
	int			final_degr;

	l_info = ft_memalloc(sizeof(l_info));
	l_info->sign = (unsigned char)g_u.ar[9] >> 7;
	l_info->pos_p = (unsigned char)(g_u.ar[9] << 1) >> 7;
	l_info->exp = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8) | g_u.ar[8];
	l_info->exp_2 = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8) | (unsigned char)g_u.ar[8];
	i = MAX_POWER_OF_LDBL;
	if (l_info->pos_p == 1 || l_info->exp < 0)
		l_info->exp += 1;
	else if (l_info->exp != 0)
		l_info->exp -= i;
	i = 8;
	l_info->mant = 0;
	while (--i >= 0)
	{
		l_info->mant = l_info->mant << 8;
		l_info->mant |= (unsigned char)g_u.ar[i];
	}
	if (!is_num_valid(l_info, str))
		return ;
	handle_decoded(l_info, str, &final_degr);
	print_num(str, -final_degr);
	free(l_info);
	return ;
}

static void	print_double(char *str, int len)
{
	if (!ft_isalnum(str[0]) && str[1] == 'n')
		return (void)print_s(str + 1, 1);
	else if ((!ft_isalnum(str[0]) && str[1] == 'i') || ft_isalpha(str[0]))
		return (void)print_s(str, 1);
	if (g_flags->minus)
	{
		ft_putstr(str);
		ft_putchars(' ', g_flags->min_width - len);
		return ;
	}
	if (!ft_isalnum(str[0]) && g_flags->zero)
			ft_putchar(*str++);
	if (g_flags->zero && g_flags->min_width)
		ft_putchars('0', g_flags->min_width - len);
	else if (g_flags->min_width)
	{
		ft_putchars(' ', g_flags->min_width - len);
		if (!ft_isalnum(str[0]))
			ft_putchar(*str++);
	}
	ft_putstr(str);
}

/*
**	Function: print_lf
**	--------------------------
**	main function for  float handling, get float format number
**	convert it to long double, after what handling flags (+,-, )
**	and convert it to string for output according to a needed precision
**	and length of integer part
**
**	num:	long long float (long double) number to print
**
**	returns:	void
*/

void		print_lf(long double num)
{
	char	s[MAX_LEN];
	char	*out;
	char	*temp;

	g_u.num = num;
	ft_bzero(s, MAX_LEN);
	if ((unsigned char)g_u.ar[9] >> 7 == 1)
	{
		s[0] = '-';
		out = s + 1;
	}
	else
	{
		if (g_flags->plus)
			s[0] = '+';
		else if (g_flags->space)
			s[0] = ' ';
		out = (g_flags->plus || g_flags->space) ? s + 1 : s;
	}
	if (g_flags->dote == 0)
		g_flags->cut = 6;
	print_f(&temp);
	ft_strcpy(out, temp);
	ft_strdel(&temp);
	print_double(s, ft_strlen(s));
}
