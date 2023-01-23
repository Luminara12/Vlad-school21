/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:41:13 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 15:08:05 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_app_input_two(char **arr, t_data *data,
	t_list **a, t_list **b)
{
	if (b_ft_strncmp(arr[data->i], "ra\n", 3) == 0)
		b_rotate_a(a);
	else if (b_ft_strncmp(arr[data->i], "rb\n", 3) == 0)
		b_rotate_b(b);
	else if (b_ft_strncmp(arr[data->i], "rr\n", 3) == 0)
		b_rotate_r(a, b);
	else if (b_ft_strncmp(arr[data->i], "rra\n", 3) == 0)
		b_rev_rotate_a(a);
	else if (b_ft_strncmp(arr[data->i], "rrb\n", 3) == 0)
		b_rev_rotate_b(b);
	else if (b_ft_strncmp(arr[data->i], "rrr\n", 4) == 0)
		b_rev_rotate_r(a, b);
	else
		b_error_message();
	return (0);
}

int	ft_app_input(char **arr, t_data *data, t_list **a, t_list **b)
{
	while (b_ft_strncmp(arr[data->i], "\n", 1) != 0)
	{
		if (arr[data->i][0] == 'r')
		{
			if (ft_app_input_two(arr, data, a, b))
				return (1);
		}
		else if (b_ft_strncmp(arr[data->i], "sa\n", 3) == 0)
			b_swap_a(*a);
		else if (b_ft_strncmp(arr[data->i], "sb\n", 3) == 0)
			b_swap_b(*b);
		else if (b_ft_strncmp(arr[data->i], "ss\n", 3) == 0)
			b_swap_ss(*a, *b);
		else if (b_ft_strncmp(arr[data->i], "pa\n", 3) == 0)
			b_push_a(a, b, &data->len_a, &data->len_b);
		else if (b_ft_strncmp(arr[data->i], "pb\n", 3) == 0)
			b_push_b(a, b, &data->len_a, &data->len_b);
		else
			b_error_message();
		data->i++;
	}
	return (0);
}

int	ft_command_input(t_list **a, t_list **b, t_data *data)
{
	char	*mas[6000];
	int		flag;

	data->i = 0;
	flag = 0;
	while (flag != 1)
	{
		mas[data->i] = get_next_line(0);
		if (b_ft_strncmp(mas[data->i], "\n", 1) == 0)
			flag = 1;
		data->i++;
	}
	data->i = 0;
	ft_app_input(mas, data, a, b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;

	data.len_b = 0;
	data.len_a = b_init_list(&a, argc, argv, &data.len_a);
	ft_command_input(&a, &b, &data);
	if (b_is_sort(a, data.len_a) == 1 && (!data.len_b))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	return (0);
}
