/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:36:40 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:19:05 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_rotate_a(t_list **a)
{
	if (!*a)
		b_error_message();
	b_rotate (a);
	return ;
}

void	b_rotate_b(t_list **b)
{
	if (!*b)
		b_error_message();
	b_rotate (b);
	return ;
}

void	b_rotate_r(t_list **a, t_list **b)
{
	if ((!*a) || (!*b))
		b_error_message();
	b_rotate(a);
	b_rotate(b);
	return ;
}

void	b_rev_rotate(t_list **a)
{
	if (!*a)
		b_error_message();
	*a = (*a)->prev;
	return ;
}

void	b_rev_rotate_a(t_list **a)
{
	if (!*a)
		b_error_message();
	b_rev_rotate (a);
	return ;
}
