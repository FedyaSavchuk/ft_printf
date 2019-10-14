//
// Created by Aileen Olen on 05/10/2019.
//

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>
#include <float.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	ft_printf("%f\n", (double)INT_MAX + 1);
	printf("%f", (double)INT_MAX + 1);
	return (0);
}