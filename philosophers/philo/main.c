/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:55:00 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 15:01:27 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	actions(t_philo *ph, t_args *data, int act_type)
{
	long	act_ti;

	act_ti = cur_ti() - data->time_lag;
	pthread_mutex_lock(&ph->in_data->write);
	ft_putnbr(act_ti);
	write(1, " ", 1);
	ft_putnbr(ph->id);
	if (act_type == 'F')
		write(1, " has taken a fork\n", 18);
	if (act_type == 'E')
		write(1, " is eating\n", 11);
	if (act_type == 'S')
		write(1, " is sleeping\n", 13);
	if (act_type == 'T')
		write(1, " is thinking\n", 13);
	pthread_mutex_unlock(&(ph->in_data->write));
}

static void	ft_magic(t_philo *ph)
{
	pthread_mutex_lock(ph->left_f);
	actions(ph, ph->in_data, 'F');
	pthread_mutex_lock(&ph->right_f);
	actions(ph, ph->in_data, 'F');
	pthread_mutex_lock(&ph->in_data->check);
	ph->st_eat = cur_ti();
	pthread_mutex_unlock(&ph->in_data->check);
	actions(ph, ph->in_data, 'E');
	ft_delay(ph->in_data->time_to_eat);
	pthread_mutex_unlock(ph->left_f);
	pthread_mutex_unlock(&ph->right_f);
	actions(ph, ph->in_data, 'S');
	ft_delay(ph->in_data->time_to_sleep);
	actions(ph, ph->in_data, 'T');
}

void	*groundhog_day(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	pthread_mutex_lock(&ph->in_data->check);
	ph->in_data->full = 0;
	pthread_mutex_unlock(&ph->in_data->check);
	if (!(ph->id % 2))
		usleep(800);
	while (ph->number_of_eat)
	{
		ft_magic(ph);
		if (ph->number_of_eat != -1)
			ph->number_of_eat--;
	}
	pthread_mutex_lock(&ph->in_data->check);
	ph->in_data->full = 1;
	ph->in_data->eat_counter++;
	pthread_mutex_unlock(&ph->in_data->check);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_args		*data;
	t_philo		*philo;
	pthread_t	*threads;

	if (argc > 6 || argc < 5)
		return (err_exit(100));
	data = args_init(argc, argv);
	if (!data)
		return (err_exit(100));
	philo = make_philo(data);
	if (!philo)
		return (err_exit(101));
	threads = make_treads(data, philo);
	if (!threads)
	{
		free(data);
		return (err_exit(101));
	}
	kill_philo(philo);
	free(threads);
	return (0);
}
