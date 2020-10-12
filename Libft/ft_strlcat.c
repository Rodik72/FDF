/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:34:40 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/21 15:34:03 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsts;
	size_t	srcs;
	size_t	i;
	int		j;

	dsts = ft_strlen(dst);
	srcs = ft_strlen(src);
	if (size < dsts)
		return (size + srcs);
	j = 0;
	i = dsts;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (srcs + dsts);
}
