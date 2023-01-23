/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b7.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:47:32 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 00:54:24 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*b_lstnew(int content)
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

void	b_lstclear(t_list *lst, t_data *data)
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

t_list	*b_lstlast(t_list *lst, int len)
{
	if (len != 1)
		return (b_lstlast(lst->next, --len));
	else
		return (lst);
}

void	b_lstadd_back(t_list **lst, t_list *new, int *len)
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

void	b_copy_list(t_list *a, t_list **c, int *len)
{
	while (a)
	{
		b_lstadd_back(c, b_lstnew(a->content), len);
		a = a->next;
	}
}
