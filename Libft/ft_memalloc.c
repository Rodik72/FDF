/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:28:26 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/17 16:00:55 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*alloc;

	alloc = (char*)malloc(sizeof(char) * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
