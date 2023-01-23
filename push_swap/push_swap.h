/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42 			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:30:41 by ptarrago          #+#    #+#             */
/*   Updated: 2022/03/11 21:39:29 by ptarrago	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				move_amount;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	int				max;
	int				min;
	int				len_a;
	int				len_b;
	struct s_list	*a;
	struct s_list	*b;
}	t_data;

int			ff(t_list *a, t_data data);
int			init_list(t_list **a, int argc, char **argv, int *len);
void		copy_list(t_list *a, t_list **c, int *len);
void		move_amount(t_list *a, t_list *b, t_data data);
void		sort_three(t_list **lst, int *len);
void		sort_six(t_list **a, t_list **b, t_data *data);
void		trans_ave(t_list **a, t_list **b, t_data *data, int mid);
void		bindex_trans(t_list **a, t_list **b, t_data *data);
int			str_is_numeric(char *str);
int			ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t count, size_t size);
t_list		*lstnew(int content);
t_list		*lstlast(t_list *lst, int len);
void		lstadd_back(t_list **lst, t_list *new, int *len);
void		lstadd_front(t_list **lst, t_list *new, int *len);
int			*lst_get_content(t_list *lst, int index);
int			is_sort(t_list *lst, int len);
void		find_min(t_list *a, t_data *data);
void		find_max(t_list *a, t_data *data);
void		error_message(void);
void		error_message_clear(t_list *a, t_data *data);
void		f_rotate(t_list **a, t_data data);
void		push_a(t_list **a, t_list **b, int *a_len, int *b_len);
void		push_b(t_list **a, t_list **b, int *a_len, int *b_len);
void		rev_rotate(t_list **a);
void		rev_rotate_a(t_list **a);
void		rev_rotate_b(t_list **b);
void		rev_rotate_r(t_list **a, t_list **b);
void		rotate(t_list **a);
void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		rotate_r(t_list **a, t_list **b);
void		swap(int *a, int *b);
void		swap_a(t_list *a);
void		swap_b(t_list *b);
void		swap_ss(t_list *a, t_list *b);
void		lstclear(t_list *lst, t_data *data);
int			quicksort(t_data *data, t_list *a);
#endif