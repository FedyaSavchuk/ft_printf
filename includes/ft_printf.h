/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:16:53 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/07 23:16:55 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft.h"

int						ft_printf(const char *format, ...);
char					read_flags(const char *f, va_list *argv);
int						clear_flags(void);
int						print_xxo(unsigned long long int nbr, char ns);
char					*ft_itoa_base(int long long value, int base, char reg);
int						print_di(long long int nbr);
int						print_u(unsigned long long int nbr);
void					print_t(char **arr);
void					print_y(char ***arr);
int						print_s(char *str);
int						print_c(char c);
int						read_file(int fd);
long long int			convert_d(va_list *argv);
unsigned long long int	convert_u(va_list *argv);
long double				convert_f(va_list *argv);
void					print_lf(long double num);
void					add_cut(char **snbr);

typedef struct			s_flags
{
	int zero;
	int minus;
	int plus;
	int grill;
	int dote;
	int space;
	int min_width;
	int cut;
	int h;
	int hh;
	int l;
	int ll;
	int cap_l;
}						t_flags;

t_flags					*g_flags;
int						g_iter;
int						g_giter;

#endif
