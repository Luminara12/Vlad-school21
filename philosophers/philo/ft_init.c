/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:55:15 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:27 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*make_treads(t_args *data, t_philo *ph)
{
	pthread_t	*th;
	int			th_ok;
	int			i;

	i = -1;
	th = malloc(sizeof(pthread_t) * (data->philo_numb + 1));
	if (!th)
		err_exit(101);
	data->time_lag = cur_ti();
	while (++i < data->philo_numb)
	{
		th_ok = pthread_create(&th[i], NULL, groundhog_day, &(ph[i]));
		if (th_ok)
			return (NULL);
		pthread_detach(th[i]);
	}
	th_ok = pthread_create(&th[data->philo_numb], NULL, inspect, ph);
	if (th_ok)
		return (NULL);
	pthread_join(th[data->philo_numb], NULL);
	return (th);
}

t_args	*args_init(int argc, char **argv)
{
	t_args	*info_strct;
	int		i;

	i = 0;
	info_strct = malloc(sizeof(t_args));
	if (!info_strct)
		return (NULL);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			free(info_strct);
			return (NULL);
		}
	}
	*info_strct = (t_args){};
	info_strct->philo_numb = ft_atoi(argv[1]);
	info_strct->time_to_die = ft_atoi(argv[2]);
	info_strct->time_to_eat = ft_atoi(argv[3]);
	info_strct->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info_strct->number_of_eat = ft_atoi(argv[5]);
	else
		info_strct->number_of_eat = -1;
	return (info_strct);
}
