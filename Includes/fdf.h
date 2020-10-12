/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:38:27 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/23 12:00:51 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "../Libft/libft.h"

# define WIN_H 1080
# define WIN_W 1920
# define BUFF_SIZE 256

typedef struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int		**map;
	int		line;
	int		column;
	int		color;
	double	add_z;
	double	padx;
	double	pady;
	double	posx;
	double	posy;
	double	posz;
	t_point	**point_data;
}				t_data;

typedef struct	s_bresenham
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	int		cumul;
	int		i;
}				t_bresenham;

int				ft_error();
int				**ft_parser(int fd, t_data *data);
void			mlx_pixel_put_to_image(void *img, int x, int y, int color);
void			ft_bresenham(t_data *data, t_point ***point);
void			ft_put_pixel(t_data *data, t_point ***point);
void			ft_projection(t_data *data);
void			display_map(t_data *data);
void			ft_key_zoom_unzoom(int keycode, t_data *data);
void			ft_key_move_map(int keycode, t_data *data);
void			ft_key_add_and_sub_z(int keycode, t_data *data);
void			ft_key_reset_map(int keycode, t_data *data);
void			ft_key_color(int keycode, t_data *data);
int				main(int argc, char **argv);

#endif
