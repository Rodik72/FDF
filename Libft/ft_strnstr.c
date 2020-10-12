/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:29:20 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 18:52:09 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*s1;
	const char	*s2;

	i = 0;
	j = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (i < len && *haystack)
	{
		s1 = haystack;
		s2 = needle;
		while (*s1 == *s2 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0' && ((i + j) <= len))
			return ((char*)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
