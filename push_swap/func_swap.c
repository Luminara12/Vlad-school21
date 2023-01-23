/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:38:06 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:38:06 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}

void	swap_a(t_list *a)
{
	write(1, "sa\n", 3);
	swap(&a->content, &a->next->content);
	return ;
}

void	swap_b(t_list *b)
{
	write(1, "sb\n", 3);
	swap(&b->content, &b->next->content);
	return ;
}

void	swap_ss(t_list *a, t_list *b)
{
	swap(&a->content, &a->next->content);
	swap(&b->content, &b->next->content);
	write(1, "ss\n", 3);
	return ;
}
