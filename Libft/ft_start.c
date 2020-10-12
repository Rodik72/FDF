/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:49:08 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 16:54:04 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_start(const char *s, char c, int i)
{
	int index;
	int word;

	word = 0;
	index = 0;
	while (s[index] && word <= i)
	{
		while (s[index] == c)
			index++;
		word++;
		while (s[index] != c && word <= i)
			index++;
	}
	return (index);
}
