/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42 			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:29 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:33:29 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	lstadd_front(t_list **lst, t_list *new, int *len)
{
	if (!lst || !new)
		return ;
	if (*len == 0)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		(*len)++;
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
	(*len)++;
}

int	*lst_get_content(t_list *lst, int index)
{
	if (index)
		return (lst_get_content(lst->next, --index));
	else
		return (&lst->content);
}

int	is_sort(t_list *lst, int len)
{
	if (len == 1)
		return (1);
	else if (lst->content < lst->next->content)
		return (is_sort(lst->next, --len));
	else
		return (0);
}
