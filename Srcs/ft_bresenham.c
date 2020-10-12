/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:01:05 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/14 17:12:47 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"
#define Y point.y
#define X point.x
#define Z point.z
#define C data->color

void	ft_bres_two(t_data *data, t_bresenham bsh)
{
	bsh.cumul = bsh.dy / 2;
	bsh.i = 0;
	while (++bsh.i <= bsh.dy)
	{
		bsh.y += bsh.yinc;
		bsh.cumul += bsh.dx;
		if (bsh.cumul >= bsh.dy)
		{
			bsh.cumul -= bsh.dy;
			bsh.x += bsh.xinc;
		}
		mlx_pixel_put_to_image(data->mlx_img, bsh.x, bsh.y, C);
	}
}

void	ft_bres_one(t_data *data, t_bresenham bsh)
{
	bsh.cumul = bsh.dx / 2;
	bsh.i = 0;
	while (++bsh.i <= bsh.dx)
	{
		bsh.x += bsh.xinc;
		bsh.cumul += bsh.dy;
		if (bsh.cumul >= bsh.dx)
		{
			bsh.cumul -= bsh.dx;
			bsh.y += bsh.yinc;
		}
		mlx_pixel_put_to_image(data->mlx_img, bsh.x, bsh.y, C);
	}
}

void	ft_trace_line(t_data *data, t_point point, t_point to_point)
{
	t_bresenham		bsh;

	bsh.x = X;
	bsh.y = Y;
	bsh.dx = to_point.x - X;
	bsh.dy = to_point.y - Y;
	bsh.xinc = (bsh.dx > 0) ? 1 : -1;
	bsh.yinc = (bsh.dy > 0) ? 1 : -1;
	bsh.dx = abs(bsh.dx);
	bsh.dy = abs(bsh.dy);
	mlx_pixel_put_to_image(data->mlx_img, bsh.x, bsh.y, C);
	if (bsh.dx > bsh.dy)
		ft_bres_one(data, bsh);
	else
		ft_bres_two(data, bsh);
}

void	ft_bresenham(t_data *data, t_point ***point)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->line)
	{
		x = 0;
		while (x < data->column)
		{
			if (y < data->line - 1)
				ft_trace_line(data, (*point)[y][x], (*point)[y + 1][x]);
			if (x < data->column - 1)
				ft_trace_line(data, (*point)[y][x], (*point)[y][x + 1]);
			if (y > 0 && x > 0 && (*point)[y][x].z == 0)
			{
				ft_trace_line(data, (*point)[y][x], (*point)[y - 1][x]);
				ft_trace_line(data, (*point)[y][x], (*point)[y][x - 1]);
			}
			x++;
		}
		y++;
	}
}
