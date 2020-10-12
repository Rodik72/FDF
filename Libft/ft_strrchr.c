/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:43:41 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/15 12:38:24 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*t;

	t = s;
	i = 0;
	while (*t)
	{
		t++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)t);
	while (i >= 0)
	{
		if (*t == (char)c)
			return ((char *)t);
		i--;
		t--;
	}
	return (NULL);
}
