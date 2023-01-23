/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42 			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:35:05 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:35:05 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	push_norm(t_list **a, t_list **b)
{
	t_list	*c;

	c = *a;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	(*a) = (*a)->next;
	(*b)->prev->next = c;
	c->prev = (*b)->prev;
	c->next = (*b);
	c->next->prev = c;
	(*b) = c;
}

static void	push(t_list **a, t_list **b, int	*a_len, int *b_len)
{
	if (*b_len == 0)
	{
		*b = *a;
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
		(*b)->prev = *b;
		(*b)->next = *b;
	}
	else if (*a_len == 1)
	{
		(*a)->next = *b;
		(*b)->prev->next = *a;
		(*a)->prev = (*b)->prev;
		(*b)->prev = *a;
		*b = *a;
		*a = NULL;
	}
	else
		push_norm(a, b);
	(*a_len)--;
	(*b_len)++;
}

void	push_a(t_list **a, t_list **b, int	*a_len, int *b_len)
{
	if (*b)
		push(b, a, b_len, a_len);
	write(1, "pa\n", 3);
	return ;
}

void	push_b(t_list **a, t_list **b, int	*a_len, int *b_len)
{
	if (*a)
		push(a, b, a_len, b_len);
	write(1, "pb\n", 3);
	return ;
}
