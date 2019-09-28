#ifndef PRINT_F
#define PRINT_F
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ... );

// список флагов к спецификаторам
typedef struct	s_flags
{
				// общие флаги
				int null;			// отвечает за ширину (при 04 будет '0025' / '25  ' )
				int minus;			// отвечает за выравнивание слева/справа
				int plus;			// отвечает за отображение знака +/- (+25 / -25)
				int grill;			// отвечает за отображение 8-16-ых чисел
				int dote;			// точность после запятой (с int работает так же как и null)
				int space;			// есть ли пробел после %

				// только для d i o u x X
				int h;				// перевод int->short_int      / unsigned_int->unsigned_short_int
				int hh;				// перевод int->char	       / unsigned_int->unsigned_char
				int l;				// перевод int->long_int  	   / unsigned_int->unsigned_long_int
				int ll;				// перевод int->long_long_int  / unsigned_int->unsigned_long_long_int

				// только для f
				// int l; Закомментирова, так как уже был этот флаг
				int L;				// перевод double->long_double
}				t_flags;

t_flags *g_flags;


#endif
