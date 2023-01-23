/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:18:27 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:26 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_exit(int flag)
{	
	if (flag == 100)
		write(2, "Error: check input:(\n", 21);
	if (flag == 101)
		write(2, "Error: smth went wrong ¯_(ツ)_/¯\n", 36);
	return (1);
}

int	analisys(t_philo *ph, int i)
{
	while (++i < ph->in_data->philo_numb)
	{
		pthread_mutex_lock(&ph->in_data->check);
		if (ph->in_data->philo_numb == ph->in_data->eat_counter)
		{
			pthread_mutex_lock(&ph->in_data->write);
			printf("All %d philo have eaten\n", ph->in_data->eat_counter);
			return (1);
		}
		pthread_mutex_unlock(&ph->in_data->check);
		pthread_mutex_lock(&ph->in_data->check);
		if ((cur_ti() - ph[i].st_eat) > (ph->in_data->time_to_die)
			&& !ph->in_data->full)
		{
			pthread_mutex_lock(&ph->in_data->write);
			printf("%ld %d died\n", cur_ti() - ph->in_data->time_lag, i + 1);
			return (1);
		}
		pthread_mutex_unlock(&ph->in_data->check);
		usleep(1000);
	}
	return (0);
}

void	*inspect(void *philo)
{
	int		i;
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		i = -1;
		if (analisys(ph, i))
			break ;
	}
	return (NULL);
}
