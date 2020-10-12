/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:30:02 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/15 12:34:30 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*sh;
	const char	*sn;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		sn = needle;
		sh = haystack;
		while (*sh == *sn && *sn)
		{
			sn++;
			sh++;
			if (*sn == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
