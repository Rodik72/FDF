/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:43:50 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/15 19:02:16 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
		i++;
	write(fd, str, i);
}