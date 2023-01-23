/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_voilà.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:29:28 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:29:28 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	trans_ave(t_list **a, t_list **b, t_data *data, int mid)
{
	int	i;

	i = data->len_a - 2;
	while (i)
	{
		if (((*a)->content != data->max) && ((*a)->content != data->min))
		{
			if ((*a)->content > mid)
			{
				push_b(a, b, &data->len_a, &data->len_b);
				rotate_b(b);
			}
			else
				push_b(a, b, &data->len_a, &data->len_b);
			i--;
		}
		else
			rotate_a(a);
	}
}

static int	bindex_seek(t_list *b, t_data *data)
{
	int	i;
	int	i_save;
	int	min_index;

	i = 0;
	i_save = 0;
	min_index = b->move_amount;
	while (i < data->len_b)
	{
		if (b->move_amount < min_index)
		{
			min_index = b->move_amount;
			i_save = i;
		}
		b = b->next;
		i++;
	}
	return (i_save);
}

static int	aindex_seek(t_list *a, int min_content)
{
	int	i;

	i = 0;
	while (!(a->prev->content < min_content && a->content > min_content))
	{
		a = a->next;
		i++;
	}
	return (i);
}

static void	aindex_trans(t_list **a, t_data *data, int min_content)
{
	int	i;
	int	a_index;

	i = 0;
	a_index = aindex_seek(*a, min_content);
	if (a_index > data->len_a - a_index)
	{
		i = data->len_a;
		while (i-- > a_index)
			rev_rotate_a(a);
	}
	else
	{
		while (i++ < a_index)
			rotate_a(a);
	}
}

void	bindex_trans(t_list **a, t_list **b, t_data *data)
{
	int	b_index;
	int	min_content;
	int	i;

	i = 0;
	b_index = bindex_seek(*b, data);
	min_content = *lst_get_content(*b, b_index);
	if (b_index > data->len_b - b_index)
	{
		i = data->len_b;
		while (i-- > b_index)
			rev_rotate_b(b);
	}
	else
	{
		while (i++ < b_index)
			rotate_b(b);
	}
	aindex_trans(a, data, min_content);
	push_a(a, b, &data->len_a, &data->len_b);
}
