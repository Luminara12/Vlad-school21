/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_minimax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:34:13 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:34:13 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	find_min(t_list *a, t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = a -> content;
	while (j < data->len_a)
	{
		if (a -> content < i)
			i = a -> content;
		a = a -> next;
		j++;
	}
	if (a -> content < i)
		i = a -> content;
	data->min = i;
}

void	find_max(t_list *a, t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = a -> content;
	while (j < data->len_a)
	{
		if (a -> content > i)
			i = a -> content;
		a = a -> next;
		j++;
	}
	if (a -> content > i)
		i = a -> content;
	data->max = i;
}

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_clear(t_list *a, t_data *data)
{
	write(2, "Error\n", 6);
	lstclear(a, data);
}
