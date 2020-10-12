/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:30:22 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 14:47:45 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*temp1;
	unsigned const char	*temp2;

	i = len - 1;
	temp1 = dst;
	temp2 = src;
	if (temp2 > temp1)
		ft_memcpy(temp1, temp2, len);
	else
	{
		while (i >= 0)
		{
			temp1[i] = temp2[i];
			i--;
		}
	}
	return (temp1);
}
