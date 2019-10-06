
#define MAX_LEN 256

#include "ft_printf.h"
#include "libft.h"

int g_last_num;

/*
** Function: copy_itoa_result
** --------------------------
** 	implements itoa to number and copy result to string and clears all temp vars.
**
**	dest:	destination string
**	num:	integer that must be transform to string
**
** 	returns:	length of copied string (dest).
*/

static int copy_itoa_result(char *dest, long int num)
{
	char *tmp;

	if (num == 0)
		return (0);
	tmp = ft_itoa_base(num, 10, 'a');
	ft_strcpy(dest, tmp);
	ft_strdel(&tmp);
	return (ft_strlen(dest));
}

/*
** Function: print_float
** --------------------------
** 	prints float and long float, both are 32-bit. Integer part transform to string
**	using itoa, the float part transform by multiplying by 10 till  get precision
**	given in g_flag->cut or 6 digits if g_flag->cut = 0
**
**	num:	float number to print
**
** 	returns:	void
*/

#include <stdio.h>

static void float2str(char *s, long double num)
{
    int u = 0;

    u = copy_itoa_result(s, (int)num);
    if ((int)num == 0)
    	s[u++] = '0';
	if (g_flags->dote == 0)
		g_flags->cut = 6;
	s[u++] = g_flags->cut == 0 ? '\0' : '.';
    while (g_flags->cut)
    {
    	if (g_flags->cut == 1)
    		g_last_num = (unsigned long int)(num * 100) % 10;
        s[u++] = ((unsigned long int)(num * 10) % 10) + '0';
        num = num * 10 - (int)num;
        g_flags->cut--;
    }
    while (g_flags->cut--)
    	s[u++] = '0';
    s[u] = '\0';
}

/*
** Function: print_double
** --------------------------
** 	prints double as long long float which is 64-bit length. Integer part transform to string
**	using itoa, the float part transform by multiplying by 10 till  get  necessary precision
**	given in g_flag->cut or 6 digits if g_flag->cut = 0
**
**	num:	long long float (double) number to print
**
** 	returns:	void
*/

//static void print_double(char *s, double num)
//{
//	long int j = 0;
//	int u = 0;
//	unsigned long int pw;
//
//	j = j + (int)num;
//	pw = 1;
//	u = copy_itoa_result(s, (int)num);
//	s[u] = '.';
//	s[u += 1] = '\0';
//	if (g_flags->dote == 0)
//		g_flags->cut = 6;
//	while (num - (j / pw) != 0.l && g_flags->cut)
//	{
//		pw = pw * 10;
//		j = j * 10;
//		j += (int) (num * pw) % 10;
//		s[u++] = ((int) (num * pw) % 10) + '0';
//		g_flags->cut--;
//	}
//	while (g_flags->cut--)
//		s[u++] = '0';
//	s[u] = '\0';
//	ft_putstr(s);
//}


/*
** Function: round_num
** --------------------------
** 	round string double number like it should be round according
**	to double rules
**
**	s:	string double ready for output
**
** 	returns:	void
*/
static void round_num(char *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	if (g_last_num == 5)
	{
		if (s[len] % 2 == 1 && s[len] < '9')
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

/*
** Function: count_num
** --------------------------
** 	counts number of digits in integer part of double (long double)
**
**	num:	long long float (double) number to print
**
** 	returns:	void
*/

static int count_num(long double num)
{
	int len;

	len = 0;
	while ((int)num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/*
** Function: print_lf
** --------------------------
** 	main function for  float handling, get float format number
**	convert it to long double, after what handling flags (+,-, )
**	and convert it to string for output according to a needed precision
**	and length of integer part
**
**	num:	long long float (double) number to print
**
** 	returns:	void
*/

void print_lf(long double num)
{
	char s[MAX_LEN];
	char *out;
	int len;
	int precision;

	precision = g_flags->cut;
	out = s;
	if (num < 0.0)
	{
		s[0] = '-';
		num *= -1.0;
		out = s + 1;
	}
	else
	{
		if (g_flags->plus)
			s[0] = '+';
		if (g_flags->space)
			s[0] = ' ';
		out = g_flags->plus || g_flags->space ? s + 1 : s;
	}
	len = count_num(num);
	if (precision <= 17 && len < 16)
	{
		out += copy_itoa_result(out, (unsigned long int) (num / 10));
		num -= ((unsigned long int) num / 10) * 10;
		float2str(out, num);
	}
	else if (len >= 16)
	{
		out += copy_itoa_result(out, (unsigned long int) num);
		*out++ = '.';
		while (precision--)
			*out++ = '0';
	}
	round_num(s);
//	else
//		dbl2str(out, num);
	ft_putstr(s);
}