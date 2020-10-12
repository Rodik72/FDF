/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:00:50 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/17 13:05:31 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(const char *src)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tmp == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	ft_strdel((char **)&src);
	return (tmp);
}
