/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_list_prepare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42   			 +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:27:30 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:27:30 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	is_norm(t_list *a, int new, int len)
{
	int	i;

	i = 1;
	a = a->next;
	while (i < len)
	{
		if ((*a).content == new)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		a = a->next;
		i++;
	}
}

int	init_list(t_list **a, int argc, char **argv, int *len)
{
	int	num;

	if (argc < 2)
		exit(0);
	num = argc - 1;
	while (argc-- > 1)
	{
		if (argv[argc][0] == '-' && argv[argc][1] == '\0')
			error_message();
		lstadd_front(a, lstnew(ft_atoi(argv[argc])), len);
		is_norm(*a, (*a)->content, *len);
	}
	return (num);
}

static int	move_amount_a(t_list *a, int i, int zero, int l)
{
	t_list	*elem;

	elem = a;
	while (elem->next)
	{
		if ((elem->content < l) && (elem->next->content > l))
		{
			if (zero < (i - zero))
				return (zero);
			else
				return (i - zero);
		}
		else
			elem = elem->next;
		zero++;
	}
	if ((elem->content < l) && (elem->next->content > l))
	{
		if (zero < (i - zero))
			return (zero);
		else
			return (i - zero);
	}
	return (0);
}

void	move_amount(t_list *a, t_list *b, t_data data)
{
	int		lenb;
	int		j;
	t_list	*elem;

	lenb = data.len_b;
	elem = b;
	j = 0;
	while (j < lenb)
	{
		if (j < (lenb - j))
			elem->move_amount = j;
		else
			elem->move_amount = lenb - j;
		elem->move_amount += move_amount_a(a, data.len_a, 0, elem->content);
		j++;
		if (elem->next)
			elem = elem->next;
	}
}
