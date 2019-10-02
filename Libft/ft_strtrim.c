/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:38:45 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:38:46 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[i] != '\0') && (s[end] == ' ' || s[end] == '\n' ||
		s[end] == '\t'))
		end--;
	res = (char *)malloc(sizeof(char) * (end - i + 1 + 1));
	if ((!res))
		return (NULL);
	while (i <= end)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
