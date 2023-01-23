/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:55:24 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:29 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(int n)
{
	long	numb;
	long	sum;

	numb = n;
	if (numb < 0)
	{
		write(1, "-", 1);
		numb *= -1;
	}
	if (numb / 10)
		ft_putnbr(numb / 10);
	sum = (numb % 10 + '0');
	write(1, &sum, 1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	res;

	i = 0;
	a = -1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = -a;
	while (str[i] == '0')
		i++;
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57)
			res = res * 10 - (str[i++] - '0');
		if (str[i])
			return (-1);
	}
	else
		return (-1);
	return (a * (int)res);
}
