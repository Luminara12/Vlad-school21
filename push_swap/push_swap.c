/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42  		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:38:47 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:38:47 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	f_rotate(t_list **a, t_data data)
{
	int	n;

	n = ff(*a, data);
	if (n <= data.len_a / 2)
	{
		while (n--)
			rotate_a(a);
	}
	else
	{
		while (data.len_a - n++)
			rev_rotate_a(a);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;

	b = NULL;
	data.len_b = 0;
	data.len_a = init_list(&a, argc, argv, &data.len_a);
	if (is_sort(a, data.len_a) == 1)
		lstclear(a, &data);
	if (data.len_a < 7)
	{
		sort_six(&a, &b, &data);
		lstclear(a, &data);
	}
	find_max(a, &data);
	find_min(a, &data);
	trans_ave(&a, &b, &data, quicksort(&data, a));
	while (data.len_b)
	{
		move_amount(a, b, data);
		bindex_trans(&a, &b, &data);
	}
	f_rotate(&a, data);
	lstclear(a, &data);
	return (0);
}
