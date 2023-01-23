/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:55 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 22:00:55 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	actions(t_args *data, int flag)
{
	long	act_ti;

	act_ti = cur_ti() - data->st_t;
	sem_wait(data->write);
	ft_putnbr(act_ti);
	write(1, " ", 1);
	ft_putnbr(data->counter);
	if (flag == 'F')
		write(1, " has taken a fork\n", 18);
	if (flag == 'E')
		write(1, " is eating\n", 11);
	if (flag == 'S')
		write(1, " is sleeping\n", 13);
	if (flag == 'T')
		write(1, " is thinking\n", 13);
	sem_post(data->write);
}

void	trunk(t_args *data)
{
	int	i;
	int	sig;

	i = -1;
	while (++i < data->philo_numb)
	{
		waitpid(-1, &sig, 0);
		if (!sig)
		{
			i = -1;
			while (++i < data->philo_numb)
				kill(data->pids[i], SIGTERM);
			return ;
		}
	}
	printf("All %d philo has finished\n", data->counter);
}

void	branches(t_args *data)
{
	pthread_t	new;

	data->counter++;
	pthread_create(&new, NULL, inspect, data);
	pthread_detach(new);
	if (!(data->counter % 2))
		usleep(500);
	while (data->number_of_eat)
	{
		sem_wait(data->fork);
		actions(data, 'F');
		sem_wait(data->fork);
		actions(data, 'F');
		data->st_eat = cur_ti();
		actions(data, 'E');
		ft_delay(data->time_to_eat);
		sem_post(data->fork);
		sem_post(data->fork);
		actions(data, 'S');
		ft_delay(data->time_to_sleep);
		actions(data, 'T');
		if (data->number_of_eat != -1)
			data->number_of_eat -= 1;
	}
	exit (1);
}

void	make_philo(t_args *data)
{
	data->counter = 0;
	while (data->counter < data->philo_numb)
	{
		data->pids[data->counter] = fork();
		if (!data->pids[data->counter])
			break ;
		data->counter++;
	}
}

int	main(int argc, char **argv)
{
	t_args		*data;

	if (argc > 6 || argc < 5)
		return (err_exit(100));
	data = args_init(argc, argv);
	if (!data)
		return (err_exit(100));
	sema_init('O', data);
	data->st_t = cur_ti();
	make_philo(data);
	if (data->counter == data->philo_numb)
		trunk(data);
	else
		branches(data);
	sema_init('D', data);
	return (0);
}
