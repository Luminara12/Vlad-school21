/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_revrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42  		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:36:32 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:36:32 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	rev_rotate(t_list **a)
{
	*a = (*a)->prev;
	return ;
}

void	rev_rotate_a(t_list **a)
{
	rev_rotate (a);
	write(1, "rra\n", 4);
	return ;
}

void	rev_rotate_b(t_list **b)
{
	rev_rotate (b);
	write(1, "rrb\n", 4);
	return ;
}

void	rev_rotate_r(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	return ;
}
