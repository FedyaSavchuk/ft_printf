//
// Created by Aileen Olen on 05/10/2019.
//

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main(void)
{
	ft_printf("{%5.0f}{%5.1lf}{%5.1Lf}\n", 7.3, 7.3, -7.3);
	printf("{%5.0f}{%5.1lf}{%5.1Lf}\n", 7.3, 7.3, -7.3);
	return (0);
}