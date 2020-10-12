/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:32:06 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/18 16:14:27 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*t;

	t = s;
	if (!s)
		return (NULL);
	if ((char)c == '\0')
	{
		while (*t != '\0')
			t++;
		return ((char *)t);
	}
	while (*t)
	{
		if (*t == (char)c)
			return ((char *)t);
		t++;
	}
	return (NULL);
}
