/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:02:45 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 16:47:04 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmpnext;

	tmp = *alst;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		(*del)(tmp->content, tmp->content_size);
		ft_memdel((void**)&tmp);
		tmp = tmpnext;
	}
	*alst = NULL;
}
