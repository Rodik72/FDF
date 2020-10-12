/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:19:11 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 14:47:04 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (*s)
	{
		tmp[i] = f(i, *s);
		i++;
		s++;
	}
	tmp[i] = '\0';
	return (tmp);
}
