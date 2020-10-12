/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:42:52 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:47 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*temp;
	unsigned const char	*temp2;

	i = 0;
	temp = dst;
	temp2 = src;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (temp2[i] == (unsigned char)c)
			return (&temp[i + 1]);
		i++;
	}
	return (NULL);
}
