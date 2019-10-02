/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:38:25 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:38:31 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_ws(const char *s, char c)
{
	unsigned int	count;
	int				f;
	int				i;

	i = -1;
	count = 0;
	f = 1;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			f = 1;
		else if (f == 1)
		{
			f = 0;
			count++;
		}
	}
	return (count);
}

static int	ft_c_cs(const char *s, int start, char c)
{
	unsigned int	len;

	len = 0;
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	return (len);
}

static char	**ft_clear_table(char ***s, int w)
{
	while (w >= 0)
	{
		if (*s[w])
			free(*s[w]);
		*s[w] = NULL;
		w--;
	}
	free(*s);
	*s = NULL;
	return (NULL);
}

static char	**ft_empty_tab(void)
{
	char	**s;

	if (!(s = (char**)malloc(sizeof(char*))))
		return (NULL);
	*s = NULL;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;
	int		j;

	if (s && ft_c_ws(s, c) == 0)
		return (ft_empty_tab());
	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_c_ws(s, c) + 1))))
		return (NULL);
	w = 0;
	j = 0;
	i = -1;
	while (s[++i] && !(j = 0) && w != ft_c_ws(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[w] = (char*)malloc(sizeof(char) * (ft_c_cs(s, i, c) + 1))))
			return (ft_clear_table(&str, w - 1));
		while (s[i] != c && s[i])
			str[w][j++] = s[i++];
		str[w++][j] = '\0';
	}
	str[w] = NULL;
	return (str);
}
