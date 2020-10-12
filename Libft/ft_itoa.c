/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:21:42 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/24 17:57:55 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int nb)
{
	size_t			len;
	unsigned int	n;
	char			*str;

	len = ft_int_len(nb);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	n = (unsigned int)nb;
	if (nb < 0)
	{
		n = (unsigned int)-nb;
		*str = '-';
	}
	else if (n == 0)
		*str = '0';
	while (len-- && n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
