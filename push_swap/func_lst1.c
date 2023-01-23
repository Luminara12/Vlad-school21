/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lst1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42  		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:32:52 by ptarrago	       #+#    #+#             */
/*   Updated: 2022/03/11 21:32:52 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_list	*lstnew(int content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem)
	{
		new_elem->content = content;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
		new_elem->move_amount = 0;
	}
	return (new_elem);
}

void	lstclear(t_list *lst, t_data *data)
{
	t_list	*tmp;
	t_list	*del;

	tmp = lst;
	while (data->len_a > 0)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		data->len_a--;
	}
	lst = NULL;
	exit(0);
}

t_list	*lstlast(t_list *lst, int len)
{
	if (len != 1)
		return (lstlast(lst->next, --len));
	else
		return (lst);
}

void	lstadd_back(t_list **lst, t_list *new, int *len)
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
	(*len)++;
}

void	copy_list(t_list *a, t_list **c, int *len)
{
	while (a)
	{
		lstadd_back(c, lstnew(a->content), len);
		a = a->next;
	}
}
