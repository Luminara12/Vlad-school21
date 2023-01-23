/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:30:34 by ptarrago          #+#    #+#             */
/*   Updated: 2022/03/26 14:21:14 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stddef.h>

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

static int	ft_isdigit(int a)
{
	if ((a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int				i;
	char			*b;
	char			q[11];
	unsigned int	nbi;

	i = 0;
	nbi = nb;
	if (nbi == 0)
		write(fd, "0", 1);
	while (nbi > 0)
	{
		q[i] = '0' + nbi % 10;
		nbi = nbi / 10;
		i++;
	}
	while (i-- > 0)
	{
		b = &q[i];
		write(fd, b, 1);
	}
}

static int	number(const char *str, int i)
{
	int		n;

	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		m;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '	')
		|| ((str[i] > 8) && (str[i] < 14)))
	{
		i++;
	}
	if (((str[i] == '-') || (str[i] == '+'))
		&& ((str[i + 1] == '-') || (str[i + 1] == '+')))
		return (0);
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	else
	{
		m = number(str, i);
	}
	return (m);
}
