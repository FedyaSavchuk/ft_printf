//
// Created by Aileen Olen on 05/10/2019.
//

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main(void)
{
	ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
	printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
	return (0);
}