/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:34:27 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:08:31 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_lstadd_front(t_list **lst, t_list *new, int *len)
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

int	b_ft_isdigit(int a)
{
	if ((a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}

int	b_ft_atoi(const char *str)
{
	int			minus;
	long int	nb;

	minus = 1;
	nb = 0;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str)
	{
		if (b_ft_isdigit(*str) == 0)
			b_error_message();
		nb = (nb * 10) + *str++ - '0';
	}
	if ((nb > 2147483647 && minus == 1) || (nb > 2147483648 && minus == -1))
		b_error_message();
	return (nb * minus);
}
