/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:35:45 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:22:38 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}

void	b_swap_a(t_list *a)
{
	if (!a)
		b_error_message();
	b_swap(&a->content, &a->next->content);
	return ;
}

void	b_swap_b(t_list *b)
{
	if (!b)
		b_error_message();
	b_swap(&b->content, &b->next->content);
	return ;
}

void	b_swap_ss(t_list *a, t_list *b)
{
	if ((!a) || (!b))
		b_error_message();
	b_swap(&a->content, &a->next->content);
	b_swap(&b->content, &b->next->content);
	return ;
}

void	b_rotate(t_list **a)
{
	if (!*a)
		b_error_message();
	*a = (*a)->next;
	return ;
}
