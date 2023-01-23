/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:49:33 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/06/09 15:09:11 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int static	ft_wdcounter(char *line)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] != ' ') && (line[i + 1] == ' '))
			counter++;
		i++;
	}
	return (counter + 1);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_wdcounter(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, int *colour_line, char *line)
{
	char	**nums;
	char	**point_stats;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		point_stats = ft_split(nums[i], ',');
		z_line[i] = ft_atoi(point_stats[0]);
		if (point_stats[1])
		{
			colour_line[i] = ft_hex_atoi(point_stats[1]);
			free(point_stats[1]);
		}
		else
			colour_line[i] = 0xFFFFFF;
		free(nums[i]);
		free(point_stats[0]);
		i++;
		free(point_stats);
	}
	free(nums);
}

void	matrix_read(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matr = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->mcolour = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->matr[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->mcolour[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matr[i], data->mcolour[i], line);
		free(line);
		i++;
	}
	close(fd);
}
