/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago ptarrago@student.42			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:26:51 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/26 04:03:53 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_delete(int *bit, int *end, char *letter)
{
	*bit = 0;
	*end = 0;
	*letter = 0;
}

void	lettercraft(int sig, siginfo_t *info, void *cont)
{
	static int	bit_number;
	static int	end_counter;
	static int	pid;
	static char	letter;

	(void)cont;
	if (!pid || pid != info->si_pid)
	{
		bit_number = 0;
		pid = info->si_pid;
	}
	letter = letter | (sig == SIGUSR1);
	end_counter += (sig == SIGUSR2);
	if (bit_number++ == 7)
	{
		if (end_counter == 8)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		write (1, &letter, 1);
		ft_delete(&bit_number, &end_counter, &letter);
	}
	else
		letter = letter << 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;

	(void)argc;
	(void)argv;
	write (1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 0);
	write (1, "\n", 1);
	s_sig.sa_sigaction = lettercraft;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
		pause();
	return (0);
}
