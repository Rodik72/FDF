/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:13 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 17:48:48 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *l;

	if ((l = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((l->content = (void*)malloc(sizeof(void) * (content_size + 1))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		l->content = ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
