/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:00:26 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:23 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_args
{
	int		philo_numb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eat;
	int		counter;
	int		pids[210];
	long	st_t;
	long	st_eat;
	int		exit_code;
	sem_t	*fork;
	sem_t	*write;
}	t_args;

int			err_exit(int flag);
int			ft_atoi(const char *str);
void		ft_delay(int mtime);
long		cur_ti(void);
t_args		*args_init(int argc, char **argv);
void		ft_putnbr(int n);

void		sema_init(int flag, t_args *data);
void		*inspect(void *philo);
void		actions(t_args *data, int flag);
void		branches(t_args *data);
void		trunk(t_args *data);
void		make_philo(t_args *data);

#endif