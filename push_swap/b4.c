/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:37:55 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:23:13 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_rev_rotate_r(t_list **a, t_list **b)
{
	if ((!*a) || (!*b))
		b_error_message();
	b_rev_rotate(a);
	b_rev_rotate(b);
	return ;
}

void	b_push_norm(t_list **a, t_list **b)
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

static void	b_push(t_list **a, t_list **b, int	*a_len, int *b_len)
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
		b_push_norm(a, b);
	(*a_len)--;
	(*b_len)++;
}

void	b_push_a(t_list **a, t_list **b, int	*a_len, int *b_len)
{
	if (*b)
		b_push(b, a, b_len, a_len);
	return ;
}

void	b_push_b(t_list **a, t_list **b, int	*a_len, int *b_len)
{
	if (*a)
		b_push(a, b, a_len, b_len);
	return ;
}
