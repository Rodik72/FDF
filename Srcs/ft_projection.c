/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:14:21 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/23 13:45:25 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"
#define Y (*point)[y][x].y
#define X (*point)[y][x].x
#define Z (*point)[y][x].z
#define DL data->line
#define DC data->column
#define PX data->padx
#define PY data->pady

void		ft_menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 0, 0xFFFFFF, \
			"====Informations====");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 30, 0xFFFFFF, \
			"Move with the Keyboards-Arrow");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 60, 0xFFFFFF, \
			"Zoom-in or Zoom-out with '+' or '-'");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 90, 0xFFFFFF, \
			"Change the height of the map with '/' or '*'");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 120, 0xFFFFFF, \
			"Change the color of the map with to this color ==>");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 510, 120, 0xFF0000, "7");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 530, 120, 0x0000FF, "8");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 550, 120, 0x00FF00, "9");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 570, 120, 0x00FFFF, "4");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 590, 120, 0xFFFF00, "5");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 610, 120, 0xFF00FF, "6");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 150, 0xFFFFFF, \
			"Reset the map with 'R'");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 0, 180, 0xFFFFFF, \
			"Quit with 'Esc'");
}

void		display_map(t_data *data)
{
	ft_put_pixel(data, &data->point_data);
	ft_bresenham(data, &data->point_data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
	ft_menu(data);
}

int			gere_key(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 69 || keycode == 78)
		ft_key_zoom_unzoom(keycode, data);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_key_move_map(keycode, data);
	if (keycode == 67 || keycode == 75)
		ft_key_add_and_sub_z(keycode, data);
	if (keycode == 15)
		ft_key_reset_map(keycode, data);
	if (keycode == 89 || keycode == 86 || keycode == 91 || keycode == 87 \
			|| keycode == 92 || keycode == 88)
		ft_key_color(keycode, data);
	return (0);
}

void		ft_put_pixel(t_data *data, t_point ***point)
{
	int			x;
	int			y;

	y = 0;
	while (y < DL)
	{
		x = 0;
		while (x < DC)
		{
			Z = (-data->map[y][x]) * data->posz * PY;
			X = (PX * (x * (WIN_W / 1.6) / DL) - PY * \
				(y * (WIN_H / 1.6) / DC) + (WIN_W / 100 * 30) + data->posx);
			Y = Z + (((PX / 2) * (x * (WIN_W / 1.6) / DL) + (PY / 2) * \
				(y * (WIN_H / 1.6) / DC) + (WIN_H / 100 * 30)) + data->posy);
			if (Y < WIN_H)
				mlx_pixel_put_to_image(data->mlx_img, X, Y, 0x00FF00);
			x++;
		}
		y++;
	}
}

void		ft_projection(t_data *data)
{
	int			y;

	data->color = 0xFFFFFF;
	PX = 0.45;
	PY = 0.75;
	data->posx = 0;
	data->posy = 0;
	data->posz = 1;
	y = 0;
	if (!(data->point_data = (t_point **)malloc(sizeof(t_point *) * DL)))
		exit(0);
	while (y < data->line)
	{
		if (!(data->point_data[y] = (t_point *)malloc(sizeof(t_point) * DC)))
			exit(0);
		y++;
	}
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Rodik");
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	display_map(data);
	mlx_hook(data->mlx_win, 2, (1L << 0), gere_key, data);
	mlx_loop(data->mlx_ptr);
}
