/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:47:21 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 16:54:22 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_len(const char *s, char c, unsigned int start)
{
	size_t	len;

	len = 0;
	while (s[start] != c && s[start])
	{
		start++;
		len++;
	}
	return (len);
}
