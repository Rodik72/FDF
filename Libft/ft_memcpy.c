/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:33:31 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 12:28:17 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*temp;
	unsigned const char	*temp2;

	i = 0;
	temp = dst;
	temp2 = src;
	while (n--)
	{
		temp[i] = temp2[i];
		i++;
	}
	return (temp);
}
