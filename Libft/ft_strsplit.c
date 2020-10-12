/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:47:00 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 16:52:51 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					**ft_strsplit(const char *s, char c)
{
	char			**tab;
	int				i;
	size_t			len;
	unsigned int	start;

	if (!s)
		return (NULL);
	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ((ft_word(s, c)) + 1))) == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		tab[0] = NULL;
		return (tab);
	}
	while (i < ft_word(s, c))
	{
		start = ft_start(s, c, i);
		len = ft_len(s, c, start);
		tab[i] = ft_strsub(s, start, len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
