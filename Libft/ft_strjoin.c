/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:46:35 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/17 14:59:10 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		i2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	if (!(s3 = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	i2 = i;
	i = 0;
	while (s2[i] != '\0')
		s3[i2++] = s2[i++];
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}
