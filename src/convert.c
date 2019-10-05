
#include "ft_printf.h"

long long int convert_d(va_list *argv)
{
	if (g_flags->hh)
		return ((long long int)(char)va_arg(*argv, int));
	if (g_flags->h)
		return ((long long int)(short int)va_arg(*argv, int));
	if (g_flags->ll)
		return ((long long int)va_arg(*argv, long long int));
	if (g_flags->l)
		return ((long long int)va_arg(*argv, long int));
	return (va_arg(*argv, int));
}

unsigned long long int convert_u(va_list *argv)
{
	if (g_flags->hh)
		return ((unsigned long long int)(unsigned char)va_arg(*argv, unsigned int));
	if (g_flags->h)
		return ((unsigned long long int)(unsigned short int)va_arg(*argv, unsigned int));
	if (g_flags->ll)
		return ((unsigned long long int)va_arg(*argv, unsigned long long int));
	if (g_flags->l)
		return ((unsigned long long int)va_arg(*argv, unsigned long int));
	return (va_arg(*argv, unsigned int));
}

long double convert_f(va_list *argv)
{
	if (g_flags->l)
		return ((long double)va_arg(*argv, double));
	if (g_flags->L)
		return ((long double)va_arg(*argv, long double));
	return ((long double)(float)va_arg(*argv, double));
}
