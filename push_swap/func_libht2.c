/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_libht2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42  		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:30:56 by ptarrago          #+#    #+#             */
/*   Updated: 2022/03/11 21:30:56 by ptarrago 	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	str_is_numeric(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (is_digit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long int	nb;

	minus = 1;
	nb = 0;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str)
	{
		if (is_digit(*str) == 0)
			error_message();
		nb = (nb * 10) + *str++ - '0';
	}
	if ((nb > 2147483647 && minus == 1) || (nb > 2147483648 && minus == -1))
		error_message();
	return (nb * minus);
}
