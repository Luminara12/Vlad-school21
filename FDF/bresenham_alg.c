/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:06:02 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/06/09 15:10:05 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_find_max(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return (x);
	else
		return (y);
}

static void	volume(t_fdf *data, int z, int z1)
{
	float	value;

	value = data->x0;
	data->x0 = (data->x0 - data->y0) * cos(data->angle_x);
	data->y0 = (value + data->y0) * sin(0.8) - z;
	value = data->x1;
	data->x1 = (data->x1 - data->y1) * cos(data->angle_x);
	data->y1 = (value + data->y1) * sin(0.8) - z1;
}

static void	expance(t_fdf *data, int z, int z1)
{
	data->x0 *= data->zoom;
	data->y0 *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	volume(data, z, z1);
	data->x0 += data->shift_x;
	data->x1 += data->shift_x;
	data->y0 += data->shift_y;
	data->y1 += data->shift_y;
}

static void	pixel_type(t_fdf *data)
{
	int		i;

	i = ((int)data->y0 * data->line_length + (int)data->x0
			* (data->bits_per_pixel / 8));
	data->img_addr[i] = data->colour;
	data->img_addr[++i] = data->colour >> 8;
	data->img_addr[++i] = data->colour >> 16;
}

void	bresenham_alg(t_fdf *data)
{
	float	dx;
	float	dy;
	float	max;
	int		z;
	int		z1;

	z = data->matr[(int)data->y0][(int)data->x0];
	z1 = data->matr[(int)data->y1][(int)data->x1];
	data->colour = data->mcolour[(int)data->y0][(int)data->x0];
	expance(data, z, z1);
	dx = data->x1 - data->x0;
	dy = data->y1 - data->y0;
	max = ft_find_max(dx, dy);
	dx /= max;
	dy /= max;
	while ((int)(data->x0 - data->x1) || (int)(data->y0 - data->y1))
	{
		if ((data->x0 < 0) || (data->x0 > 1920))
			break ;
		if ((data->y0 < 0) || (data->y0 > 1080))
			break ;
		pixel_type(data);
		data->x0 += dx;
		data->y0 += dy;
	}
}
