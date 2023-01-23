/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:12:28 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:31 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	cur_ti(void)
{
	struct timeval	time;
	long			value;

	gettimeofday(&time, NULL);
	value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (value);
}

void	ft_delay(int mtime)
{
	long		start;

	start = cur_ti();
	usleep(mtime * 950);
	while ((mtime + start) > cur_ti())
		usleep(250);
}
