/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:19:35 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/23 13:48:17 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void			ft_malloc_map(char **map_ascii, int ***map, t_data *data)
{
	int		y;
	int		savey;
	int		savex;
	char	**tmp;

	savey = -1;
	savex = 0;
	y = 0;
	while (map_ascii[y])
		y++;
	data->line = y;
	tmp = ft_strsplit(map_ascii[y - 1], ' ');
	while (tmp[savex])
		free(tmp[savex++]);
	free(tmp);
	data->column = savex;
	((*map) = (int **)malloc(sizeof(int *) * (y + 1)));
	while (savey++ < y)
	{
		savex = -1;
		((*map)[savey] = (int *)malloc(sizeof(int) * (data->column + 1)));
		while (savex++ < data->column)
			(*map)[savey][savex] = 0;
	}
}

void			ft_fill_struct_map(char **map_ascii, int ***map, t_data *data)
{
	char		**tmp;
	int			x;
	int			y;

	y = 0;
	while (map_ascii[y])
	{
		x = 0;
		tmp = ft_strsplit(map_ascii[y], ' ');
		while (tmp[x] != NULL)
		{
			(*map)[y][x] = ft_atoi(tmp[x]);
			data->add_z += (*map)[y][x];
			ft_putnbr((*map)[y][x]);
			free(tmp[x]);
			x++;
		}
		ft_putchar('\n');
		free(tmp);
		y++;
	}
}

int				ft_error(char **map_ascii)
{
	char	**split;
	int		i;
	int		save;
	int		count;

	save = 0;
	i = 0;
	while (map_ascii[i])
	{
		split = ft_strsplit(map_ascii[i], ' ');
		count = 0;
		while (split[count])
		{
			free(split[count]);
			count++;
		}
		free(split);
		if (i == 0)
			save = count;
		if (save != count)
			return (1);
		i++;
	}
	return (0);
}

void			ft_free_map_ascii(char **map_ascii)
{
	int	i;

	i = 0;
	while (map_ascii[i])
	{
		free(map_ascii[i]);
		i++;
	}
	free(map_ascii);
}

int				**ft_parser(int fd, t_data *data)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	char		**map_ascii;
	int			**map;

	ret = 1;
	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = !tmp ? ft_strdup(buf) : ft_strjoinfree(tmp, buf, 1);
	}
	map_ascii = ft_strsplit(tmp, '\n');
	free(tmp);
	if (ft_error(map_ascii) == 1)
	{
		ft_putendl("Map Error");
		exit(-1);
	}
	ft_malloc_map(map_ascii, &map, data);
	ft_fill_struct_map(map_ascii, &map, data);
	ft_free_map_ascii(map_ascii);
	return (map);
}
