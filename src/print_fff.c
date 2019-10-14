/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:49:28 by pmila             #+#    #+#             */
/*   Updated: 2019/10/14 15:17:26 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_printf.h"
#define LD long double
#define LL unsigned long long
#define DEG_OF_5_7 "78125"
#define DEG_OF_5_14 "6103515625"
#define MAX_LEN 512

typedef struct	s_ldouble
{
	LL			mant;
	char		sign;
	char		pos_p;
	int			exp;
	unsigned int	exp_2;
}				t_ld;


typedef union	s_un
{
	long double	num;
	char		ar[sizeof(long double)];
}				t_un;

t_un		g_u;

void	get_degr_of_five(char **str, int degr)
{
	char	*tmp;

	tmp = ft_memalloc(degr + 1);
	if (degr >= 7)
	{
		ft_strcpy(tmp, DEG_OF_5_7);
		degr -= 7;
	}
	else if (degr-- > -1)
		ft_strcpy(tmp, "5");
	while (degr >= 7)
	{
		infin_mult(&tmp, DEG_OF_5_7);
		degr -= 7;
	}
	while (degr >= 1)
	{
		infin_mult(&tmp, "5");
		degr -= 1;
	}
	*str = ft_strdup(tmp);
	free(tmp);
}

/*
static void	round_num(char *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	if (g_last_num == 5)
	{
		if (s[len] % 2 == 1 && s[len] < ' 9')
			s[len]++;
	}
	else if (g_last_num > 5)
	{
		if (s[len] < '9')
			s[len]++;
		else
			while (s[len] == '9')
			{
				s[len] = '0';
				len--;
			}
		s[len]++;
	}
}
*/
int		round_last(char *str, int k)
{
	int	i;

	i = 2;
	if (str[k + 1] == '\0')
		return (0);
	else if (str[k + 1] && str[k + 1] > '5')
		return (1);
	else if (str[k + 1] && str[k + 1] < '5')
		return (0);
	while (str[k + i] != '\0')
		if (str[k + i++] > '0')
			return (1);
	if ((str[k] - '0') % 2 == 0)
		return (0);
	return (1);
}

void	print_res(char *result, char **str)
{
	int		i;

	i = 0;
	free(*str);
	if (result[0] == '0' && result[1] != '.')
		result++;
	*str = ft_strdup(result);
}

void	check_round(char **str, int j)
{
	while (j > 0 && (*str)[j] > '9')
	{
		(*str)[j] = '0';
		if ((*str)[j - 1] == '.')
			j--;
		(*str)[j - 1] += 1;
		j--;
	}
}

void	handle_integer(char **result, int i, char *str)
{
	int		j;
	int		k;

	j = 2;
	k = 0;
	if (i <= 0)
		(*result)[j++] = '0';
	while (i-- > 0 && str[k] != '\0')
		(*result)[j++] = str[k++];
	(*result)[j - 1] += round_last(str, k - 1);
	check_round(result, j - 1);
	if (g_flags->grill == 1)
		(*result)[j++] = '.';
	(*result)[j] = '\0';
}

void	print_num(char **str, int degr)
{
	char	*result;
	int		i;
	int		k;
	int		j;

//	ft_putstr(str);
//	ft_putchar('\n');
	//printf("degr = %d\n", degr);
	i = ft_strlen((*str));
	result = ft_memalloc(i + g_flags->cut + 2);
	i -= degr;
//	printf("%d\n", i);
//	printf("%d\n", sign);
	j = 0;
	k = 0;
	if (g_flags->dote == 0)
		g_flags->cut = 6;
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
			{
	//			printf("12334\n");
				result[j++] = (*str)[k++];
			}
			i += 2;
		}
		if (!(*str)[k])
			while (g_flags->cut-- > 0)
			{
//				printf("%d\n", g_flags->cut);
				result[j++] = '0';
			}
		else if(i == 0)
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

int		numlen (LL mant)
{
	int		len;

	len = 0;
	while (mant > 0)
	{
		mant /= 10;
		len++;
	}
	return (len);
}

void	get_str_mant(char **str, t_ld *l_info)
{
	int		i;

	i = numlen(l_info->mant);
	while (l_info->mant > 0)
	{
		i -= 1;
		(*str)[i] = (l_info->mant % 10) + '0';
		l_info->mant = l_info->mant / 10;
	}
}

void	multiplication(char *five, int *degr, char **str)
{
	if (*degr < 0)
		infin_mult(str, five);
//	printf("%s\n", str);
	while (*degr > 0)
	{
		infin_mult(str, "2");
		(*degr)--;
	}
}

void	handle_decoded(t_ld *l_info, char **str, int *final_degr)
{
	int			mant_denom;
	char		*five;

//	printf("exp = %d\n", l_info->exp);
	five = NULL;
	mant_denom = 63;
	while ((unsigned char)l_info->mant == 0 && mant_denom > 7)
	{
		l_info->mant = l_info->mant >> 8;
		mant_denom -= 8;
	}
//	printf("mant= %llu\n", l_info->mant);
	*final_degr = l_info->exp - mant_denom;
//	printf("power of 2:  %d\n", final_degr);
	if (*final_degr < 0)
		get_degr_of_five(&five, -(*final_degr));
	(*str) = ft_memalloc(ft_strlen(five) + 22);
//	printf("l_info->mant (llu) %llu\n", l_info->mant);
	get_str_mant(str, l_info);
//	printf("%s\n", five);
	multiplication(five, final_degr, str);
}

int		is_num_valid(t_ld *l_info, char **str)
{
	int		i;

	i = (g_flags->cap_l ? 16383 : 127);
	i = (g_flags->l ? 1023 : i);
	if (l_info->pos_p == 1 || l_info->exp_2 < 1)
		l_info->exp_2 += 1;
	else if (l_info->exp_2 == 0)
		l_info->pos_p = -1;
	else
		l_info->exp_2 -= i;
	if ((g_flags->cap_l == 1 && l_info->exp_2 == 16384) || (g_flags->l == 1 &&
				l_info->exp_2 == 1024) || ((!g_flags->l) && (!g_flags->cap_l) &&
															l_info->exp_2 == 128))
	{
		*str = ft_memalloc(4);
		if ((l_info->mant << 1) != 0)
			*str = ft_strdup("nan\0");
		else
		{
			*str = ft_strdup("inf\0");
		}
		return (0);
	}
	return (1);
}

char	*print_f(long double num)
{
	t_ld		*l_info;
	int			i;
	char		*str;
	int		final_degr;

	l_info = malloc(sizeof(l_info));
	g_u.num = num;
	//handling an exponent
	l_info->sign = (unsigned char)g_u.ar[9] >> 7;
//	printf("l_info->sign = %d\n", sign);
	l_info->pos_p = (unsigned char)(g_u.ar[9] << 1) >> 7;
//	printf("l_info->pos_p = %d\n", l_info->pos_p);
	l_info->exp = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8) | g_u.ar[8];
	l_info->exp_2 = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8) | (unsigned char)g_u.ar[8];
	if (l_info->pos_p == 1 || l_info->exp < 0)
		l_info->exp += 1;
	else if (l_info->exp == 0)
		l_info->pos_p = -1;
	else
		l_info->exp -= 127;
//	printf("l_info->exp = %d\n", l_info->exp);

	//handling a mantissa
	i = 8;
	l_info->mant = 0;
	while (--i >= 0)
	{
		l_info->mant = l_info->mant << 8;
		l_info->mant |= (unsigned char)g_u.ar[i];
	}
	if (!is_num_valid(l_info, &str))
		return (str);
	handle_decoded(l_info, &str, &final_degr);
	print_num(&str, -final_degr);
	free(l_info);
	return(str);
}


static void	print_double(char *str, int len)
{
	if (!ft_isdigit(str[0]) && g_flags->zero)
			ft_putchar(*str++);
	if (g_flags->zero)
		ft_putchars('0', g_flags->min_width - len);
	else
	{
		ft_putchars(' ', g_flags->min_width - len);
		ft_putchar(*str++);
	}
	if (ft_isdigit(*str))
		ft_putstr(str);
	else
		ft_putstr(str + 1);
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
	int		precision;

	precision = g_flags->cut;
	ft_bzero(s, MAX_LEN);
	if ((unsigned char)g_u.ar[9] >> 7 == 1)
	{
		s[0] = '-';
		num *= -1.0;
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
//	len = count_num(num);
//	if (precision <= 17 && len < 16)
//	{
//		out += copy_itoa_result(out, (unsigned long int)(num / 10));
//		num -= ((unsigned long int)(num / 10)) * 10;
//		float2str(out, num);
//	}
//	else if (len >= 16)
//	{
//		out += copy_itoa_result(out, (unsigned long int)num);
//		*out++ = '.';
//		while (precision--)
//			*out++ = '0';
//	}
//	else
	ft_strcpy(out, print_f(num));
//	round_num(s);
	print_double(s, ft_strlen(s));
}
