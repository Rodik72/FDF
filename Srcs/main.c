/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:37:01 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/23 11:17:25 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_data		data;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || (fd < 0))
	{
		ft_putstr("usage : fdf target_file");
		return (0);
	}
	data.map = ft_parser(fd, &data);
	ft_projection(&data);
	return (0);
}
