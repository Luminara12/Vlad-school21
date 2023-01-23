/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42		   	  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:16:53 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/26 03:46:10 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	morse_forwarding(int pid, char letter, int bit_number)
{
	if (letter >> bit_number & 1)
	{
		if (kill(pid, SIGUSR1) < 0)
			return (1);
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
			return (1);
	}
	return (0);
}

static int	letter_forwarding(int pid, char letter)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (morse_forwarding(pid, letter, i))
			return (1);
		usleep(100);
	}
	return (0);
}

static void	message_forwarding(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (letter_forwarding(pid, str[i]))
		{
			write(1, "Volvo fix PID please\n", 21);
			exit(0);
		}
		i++;
	}
	if (letter_forwarding(pid, str[i]))
	{
		write(1, "Volvo fix PID please\n", 21);
		exit(0);
	}
}

static void	ft_answer(int sig, siginfo_t *info, void *cont)
{
	(void)info;
	(void)cont;
	if (sig == SIGUSR2)
	{
		write (1, "Roger that\n", 11);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigb;
	int					pid;

	s_sigb.sa_sigaction = ft_answer;
	s_sigb.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigb, NULL);
	sigaction(SIGUSR2, &s_sigb, NULL);
	if (argc != 3)
	{
		write(1, "wrong number of argc\n", 21);
		exit(0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		message_forwarding(pid, argv[2]);
	}
	return (0);
}
