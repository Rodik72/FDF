/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:50:07 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/18 15:58:39 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(const char *s1, const char *s2, int index)
{
	char	*s3;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	s3 = ft_strcat(s3, s1);
	s3 = ft_strcat(s3, s2);
	if (index == 1 || index == 3)
	{
		free((void *)s1);
		s1 = NULL;
	}
	else if (index == 2 || index == 3)
	{
		free((void *)s2);
		s2 = NULL;
	}
	return (s3);
}
