
#include "printf.h"

void	print_t(char **arr)
{
	int j;

	j = 0;
	while (arr[j])
	{
		ft_putstr(arr[j]);
		ft_putchar('\n');
		j++;
	}
}

void	print_y(char ***arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i])
		{
			ft_putstr(arr[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		read_file(int fd)
{
	int count;
	char buff[BUFF_SIZE + 1];

	if (fd < 0)
		return (-1);
	count = 1;
	while (count != 0)
	{
		count = read(fd, buff, BUFF_SIZE);
		buff[count] = '\0';
		ft_putstr(buff);
	}
	return (0);
}