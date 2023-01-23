/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:29:09 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:19 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sema_init(int flag, t_args *data)
{
	if (flag == 'O')
	{
		sem_unlink("fork");
		sem_unlink("write");
		data->fork = sem_open("fork", O_CREAT, S_IRWXU, data->philo_numb);
		data->write = sem_open("write", O_CREAT, S_IRWXU, 1);
	}
	else if (flag == 'D')
	{
		sem_close(data->fork);
		sem_close(data->write);
		sem_unlink("fork");
		sem_unlink("write");
	}
}

t_args	*args_init(int argc, char **argv)
{
	t_args	*info_strct;
	int		i;

	i = 0;
	info_strct = malloc(sizeof (t_args));
	if (!info_strct)
		return (NULL);
	while (++i < argc)
		if (ft_atoi(argv[i]) <= 0)
			return (NULL);
	*info_strct = (t_args){};
	info_strct->philo_numb = ft_atoi(argv[1]);
	info_strct->time_to_die = ft_atoi(argv[2]);
	info_strct->time_to_eat = ft_atoi(argv[3]);
	info_strct->time_to_sleep = ft_atoi(argv[4]);
	info_strct->number_of_eat = -1;
	if (argc == 6)
		info_strct->number_of_eat = ft_atoi(argv[5]);
	else
		info_strct->number_of_eat = -1;
	info_strct->st_eat = cur_ti();
	return (info_strct);
}
