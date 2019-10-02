#include "printf.h"

void	print_t(char **arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i])
			ft_putchar(arr[j][i++]);
		ft_putchar('\n');
		j++;
	}
}
