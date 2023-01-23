/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:38:33 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:23:08 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_rev_rotate_b(t_list **b)
{
	if (!*b)
		b_error_message();
	b_rev_rotate (b);
	return ;
}

int	b_is_sort(t_list *lst, int len)
{
	if (len == 1)
		return (1);
	else if (lst->content < lst->next->content)
		return (b_is_sort(lst->next, --len));
	else
		return (0);
}

static void	b_is_norm(t_list *a, int new, int len)
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

int	b_init_list(t_list **a, int argc, char **argv, int *len)
{
	int	num;

	if (argc < 2)
		exit(0);
	num = argc - 1;
	while (argc-- > 1)
	{
		if (argv[argc][0] == '-' && argv[argc][1] == '\0')
			b_error_message();
		b_lstadd_front(a, b_lstnew(b_ft_atoi(argv[argc])), len);
		b_is_norm(*a, (*a)->content, *len);
	}
	return (num);
}

char	*b_ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((s1 == 0) && (s2 == 0))
		return (0);
	else if (s1 == 0)
		return ((char *)s2);
	res = malloc(sizeof(char) * (b_ft_strlen(s1) + b_ft_strlen(s2)) + 1);
	if (res == 0)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
