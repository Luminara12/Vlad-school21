/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:20:52 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 15:01:30 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int					philo_numb;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_eat;
	long				time_lag;
	int					eat_counter;
	int					exit_code;
	int					full;
	pthread_mutex_t		check;
	pthread_mutex_t		write;
}	t_args;

typedef struct s_philo
{
	t_args				*in_data;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		right_f;
	int					id;
	int					eat_iter;
	long				st_eat;
	int					number_of_eat;
}	t_philo;

int			err_exit(int flag);
int			ft_atoi(const char *str);
void		ft_delay(int mtime);
long		cur_ti(void);
t_args		*args_init(int argc, char **argv);

void		*groundhog_day(void *ph);
void		actions(t_philo *ph, t_args *data, int act_type);
t_philo		*make_philo(t_args *data);
pthread_t	*make_treads(t_args *data, t_philo *ph);
void		kill_philo(t_philo *ph);

void		*inspect(void *ph);
void		ft_putnbr(int n);
#endif