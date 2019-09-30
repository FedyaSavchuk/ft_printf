
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
		{
			ft_putchar(arr[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		search_min_width()
{

	return();
}

void	print_y(char ***arr)
{
	int i;
	int j;
	int k;

	j = 0;
	// нахожу минимальную строку
	while (arr[line])
	{
		column = 0;
		while (arr[line][column])
		{
			i = 0;
			while (arr[line][column][i])
			{
				i++;
			}
			write(1, "  ", 2);
			column++;
		}
		write(1, "\n", 1);
		line++;
	}
}