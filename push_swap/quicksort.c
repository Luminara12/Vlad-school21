/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:27:39 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/03 22:46:53 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort(int max, int *mas)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	while (i + 1 <= max)
	{
		if (mas[i] > mas[i + 1])
		{
			tmp = mas[i];
			mas[i] = mas[i + 1];
			mas[i + 1] = tmp;
		}
		i++;
	}
}

static void	bubble(int *mas)
{
	int	max;

	max = 0;
	while (mas[max])
		max++;
	while (max-- > 1)
		sort(max, mas);
}

int	quicksort(t_data *data, t_list *a)
{
	int		*mas;
	int		i;
	t_list	*lst;

	i = 0;
	lst = a;
	mas = malloc(sizeof(int) * (data->len_a));
	while (i < data->len_a)
	{
		mas[i] = lst->content;
		lst = lst->next;
		i++;
	}
	bubble(mas);
	free(mas);
	return (mas[(data->len_a) / 2]);
}
