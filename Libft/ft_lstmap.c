/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:48:26 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 18:03:33 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *head;
	t_list *node;

	head = NULL;
	while (lst != NULL)
	{
		node = (*f)(lst);
		if (head == NULL)
			head = node;
		else
			tmp->next = node;
		tmp = node;
		lst = lst->next;
	}
	return (head);
}
