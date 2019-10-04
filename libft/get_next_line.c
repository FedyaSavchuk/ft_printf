/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:09:36 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/16 14:09:38 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*get_fd(t_list **lst, int fd)
{
	t_list	*node;

	if (!*lst)
		*lst = ft_lstnew(0, 0);
	node = *lst;
	while (node)
	{
		if (((int)(node)->content_size) == fd && (node)->content)
			return (node);
		if (!(node)->next)
			break ;
		node = (node)->next;
	}
	node->next = ft_lstnew("\0", 1);
	node->next->content_size = fd;
	return (node->next);
}

static char		*get_line(char **src)
{
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	while ((*src)[i] && (*src)[i] != '\n')
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, *src, i);
	tmp = ft_strdup(&((*src)[i]));
	ft_memdel((void*)src);
	*src = tmp;
	if (ft_strchr(*src, '\n'))
		*src = ft_strdup(ft_strchr(*src, '\n') + 1);
	else
		*src = ft_strdup("\0");
	ft_memdel((void*)&tmp);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static	t_list	*lst_save;
	t_list			*lst;
	int				size;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	lst = get_fd(&lst_save, fd);
	size = 0;
	while (!(ft_strchr(lst->content, '\n')) &&
		(size = read(lst->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		lst->content = ft_strjoinfree((char**)&(lst->content), buf);
	}
	if (size == -1 || (!size && !ft_strlen(lst->content)))
		return (size);
	*line = get_line((char**)(&lst->content));
	return (1);
}
