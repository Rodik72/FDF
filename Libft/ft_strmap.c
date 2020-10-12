/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:53:52 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/18 17:07:43 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (*s)
	{
		tmp[i] = f(*s);
		i++;
		s++;
	}
	tmp[i] = '\0';
	return (tmp);
}
