/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:24:27 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/06/09 15:09:55 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	data_x_y(t_fdf *data, int x, int y)
{
	data->x0 = x;
	data->x1 = x;
	data->y0 = y;
	data->y1 = y;
}

static void	draw_lines(t_fdf *data, int x, int y)
{
	data_x_y(data, x, y);
	if (x < data->width - 1)
	{
		data->x1 += 1;
		bresenham_alg(data);
		data_x_y(data, x, y);
	}
	if (y < data->height - 1)
	{
		data->y1 += 1;
		bresenham_alg(data);
		data_x_y(data, x, y);
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_lines(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
