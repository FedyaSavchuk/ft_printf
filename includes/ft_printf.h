#ifndef PRINT_F
#define PRINT_F
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft.h"

int						ft_printf(const char *format, ... );
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

// список флагов к спецификаторам
typedef struct	s_flags
{
				// общие флаги
				int zero;			// отвечает за ширину (при 04 будет '0025' / '25  ' )
				int minus;			// отвечает за выравнивание слева/справа
				int plus;			// отвечает за отображение знака +/- (+25 / -25)
				int grill;			// отвечает за отображение 8-16-ых чисел
				int dote;			// точность после запятой (с int работает так же как и zero)
				int space;			// есть ли пробел после %
				int min_width;		// минимальная ширина строки
				int cut;			// сколько символов нужно обрезать после точки (.5)

				// только для d i o u x X
				int h;				// перевод int->short_int      / unsigned_int->unsigned_short_int
				int hh;				// перевод int->char	       / unsigned_int->unsigned_char
				int l;				// перевод int->long_int  	   / unsigned_int->unsigned_long_int
				int ll;				// перевод int->long_long_int  / unsigned_int->unsigned_long_long_int

				// только для f
				//int l; /Закомментирова, так как уже был этот флаг
				int L;				// перевод double->long_double
}				t_flags;

t_flags *g_flags;

int g_iter;
int g_giter;

#endif
