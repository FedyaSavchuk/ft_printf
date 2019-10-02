/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:35:02 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/09 20:35:03 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delcontent(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list_start;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	list_start = list;
	lst = lst->next;
	while (lst)
	{
		list->next = f(lst);
		if (!list->next)
		{
			ft_lstdel(&list_start, delcontent);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (list_start);
}
