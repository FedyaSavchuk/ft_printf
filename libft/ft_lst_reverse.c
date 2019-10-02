/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:21:08 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/10 15:21:10 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_reverse(t_list *alst)
{
	t_list	*rev;
	t_list	*tmp;
	t_list	*next;

	if (!alst || !(tmp = alst))
		return (NULL);
	rev = NULL;
	while (tmp)
	{
		next = tmp->next;
		tmp->next = rev;
		rev = tmp;
		tmp = next;
	}
	return (rev);
}
