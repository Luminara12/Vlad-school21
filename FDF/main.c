/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:09:31 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/11 12:35:43 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

int	hotkeys(int key, t_fdf *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 6)
		data->zoom *= 2;
	if (key == 7)
		data->zoom /= 2;
	if (key == 0)
		data->angle_x += 0.1;
	if (key == 2)
		data->angle_x -= 0.1;
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	draw_map(data);
	return (0);
}

static void	ft_free(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->matr[i])
	{
		free(data->matr[i]);
		free (data->mcolour[i]);
		i++;
	}
	free(data->matr[i]);
	free(data->matr);
	free(data->mcolour[i]);
	free(data->mcolour);
	free(data);
}

static	int	ft_exit(void *smth)
{
	(void)smth;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		exit(0);
	data = malloc(sizeof(t_fdf));
	if (!data)
		ft_exit (0);
	data->zoom = 10;
	data->angle_x = 0.8;
	data->shift_x = 400;
	data->shift_y = 400;
	matrix_read(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1080);
	draw_map(data);
	mlx_key_hook(data->win_ptr, hotkeys, data);
	mlx_hook(data->win_ptr, 2, 0, hotkeys, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
	ft_free(data);
	return (0);
}
