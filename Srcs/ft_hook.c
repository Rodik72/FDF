/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:51:53 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/23 13:43:33 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"
#define PX data->padx
#define PY data->pady
#define DC data->column
#define DL data->line

void	ft_key_zoom_unzoom(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (keycode == 69)
	{
		PX += (PX / 100 * 8);
		PY += (PY / 100 * 8);
	}
	if (keycode == 78)
	{
		PX -= (PX / 100 * 8);
		PY -= (PY / 100 * 8);
	}
	display_map(data);
}

void	ft_key_move_map(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (keycode == 123)
		data->posx += ((WIN_W) / 100 * 2);
	if (keycode == 124)
		data->posx -= ((WIN_W) / 100 * 2);
	if (keycode == 125)
		data->posy -= ((WIN_H) / 100 * 2);
	if (keycode == 126)
		data->posy += ((WIN_H) / 100 * 2);
	display_map(data);
}

void	ft_key_add_and_sub_z(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (keycode == 67)
		data->posz += ((WIN_H) / 100 * 0.1);
	if (keycode == 75)
		data->posz -= ((WIN_H) / 100 * 0.1);
	display_map(data);
}

void	ft_key_reset_map(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (keycode == 15)
	{
		data->posz = 1;
		data->posy = 0;
		data->posx = 0;
		PX = 0.5;
		PY = 0.75;
		data->color = 0xFFFFFF;
	}
	display_map(data);
}

void	ft_key_color(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (keycode == 89)
		data->color = 0xFF0000;
	if (keycode == 86)
		data->color = 0x00FFFF;
	if (keycode == 91)
		data->color = 0x0000FF;
	if (keycode == 87)
		data->color = 0xFFFF00;
	if (keycode == 92)
		data->color = 0x00FF00;
	if (keycode == 88)
		data->color = 0xFF00FF;
	display_map(data);
}
