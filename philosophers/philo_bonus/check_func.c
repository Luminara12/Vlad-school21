/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:35:40 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:18 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	err_exit(int flag)
{	
	if (flag == 100)
		write(2, "Error: check input:(\n", 21);
	if (flag == 101)
		write(2, "Error: smth went wrong ¯_(ツ)_/¯\n", 36);
	exit (1);
}

void	*inspect(void *data)
{
	t_args	*ph;

	ph = (t_args *)data;
	while (1)
	{
		if ((cur_ti() - ph->st_eat) > (ph->time_to_die))
		{
			sem_wait(ph->write);
			printf("%ld %d died\n", cur_ti() - ph->st_t, ph->counter);
			exit (0);
		}
		usleep(500);
	}
}
