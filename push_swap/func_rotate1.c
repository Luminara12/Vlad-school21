/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:37:26 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:37:35 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	rotate(t_list **a)
{
	*a = (*a)->next;
	return ;
}

void	rotate_a(t_list **a)
{
	rotate (a);
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_list **b)
{
	rotate (b);
	write(1, "rb\n", 3);
	return ;
}

void	rotate_r(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return ;
}
