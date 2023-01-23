/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:50:49 by ptarrago          #+#    #+#             */
/*   Updated: 2021/10/23 17:25:24 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"

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
	int		s;

	i = 0;
	s = 1;
	while ((str[i] == ' ') || (str[i] == '	')
		|| ((str[i] > 8) && (str[i] < 14)))
	{
		i++;
	}
	if (str[i] == '-')
		s = s * (-1);
	if (((str[i] == '-') || (str[i] == '+'))
		&& ((str[i + 1] == '-') || (str[i + 1] == '+')))
		return (0);
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	else
	{
		m = number(str, i);
	}
	return (m * s);
}
