/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:24:24 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/06/09 15:09:39 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <math.h>

typedef struct s_fdf
{
	int		height;
	int		width;
	int		**matr;
	int		**mcolour;
	void	*mlx_ptr;
	void	*win_ptr;
	float	zoom;
	int		colour;
	int		shift_x;
	int		shift_y;
	float	angle_x;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_matrix(int *z_line, int *colour_line, char *line);
void	matrix_read(char *file_name, t_fdf *data);
void	bresenham_alg(t_fdf *data);
int		hotkeys(int key, t_fdf *data);
void	draw_map(t_fdf *data);

#endif