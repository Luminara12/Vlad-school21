/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_staff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:22:27 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:30 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_philo(t_args *data)
{
	t_philo		*ph;
	int			i;

	i = -1;
	ph = malloc(sizeof(t_philo) * data->philo_numb);
	if (!ph)
		return (NULL);
	while (++i < data->philo_numb)
	{
		ph[i] = (t_philo){};
		ph[i].id = i + 1;
		ph[i].in_data = data;
		ph[i].number_of_eat = data->number_of_eat;
		ph[i].st_eat = cur_ti();
		pthread_mutex_init(&ph[i].right_f, NULL);
	}
	i = 0;
	while (++i < data->philo_numb)
		ph[i].left_f = &ph[i - 1].right_f;
	ph[0].left_f = &ph[i - 1].right_f;
	pthread_mutex_init(&ph->in_data->write, NULL);
	pthread_mutex_init(&ph->in_data->check, NULL);
	return (ph);
}

void	kill_philo(t_philo *ph)
{
	while (ph->in_data->philo_numb > 0)
	{
		pthread_mutex_destroy(&ph[ph->in_data->philo_numb].right_f);
		(ph->in_data->philo_numb)--;
	}
	pthread_mutex_destroy(&ph->in_data->write);
	pthread_mutex_destroy(&ph->in_data->check);
	free(ph->in_data);
	free(ph);
}
