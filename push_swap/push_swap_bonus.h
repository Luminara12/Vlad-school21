/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:05:52 by ptarrago          #+#    #+#             */
/*   Updated: 2022/07/06 01:25:34 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
	int				i;
	struct s_list	*a;
	struct s_list	*b;
}	t_data;

int			b_ff(t_list *a, t_data data);
int			b_init_list(t_list **a, int argc, char **argv, int *len);
void		b_copy_list(t_list *a, t_list **c, int *len);
int			b_str_is_numeric(char *str);
int			b_ft_atoi(const char *str);
char		*b_ft_substr(char const *s, unsigned int start, size_t len);
void		*b_ft_calloc(size_t count, size_t size);
t_list		*b_lstnew(int content);
t_list		*b_lstlast(t_list *lst, int len);
void		b_lstadd_back(t_list **lst, t_list *new, int *len);
void		b_lstadd_front(t_list **lst, t_list *new, int *len);
int			*b_lst_get_content(t_list *lst, int index);
int			b_is_sort(t_list *lst, int len);
void		b_find_min(t_list *a, t_data *data);
void		b_find_max(t_list *a, t_data *data);
void		b_error_message(void);
void		b_push_a(t_list **a, t_list **b, int *a_len, int *b_len);
void		b_push_b(t_list **a, t_list **b, int *a_len, int *b_len);
void		b_rev_rotate(t_list **a);
void		b_rev_rotate_a(t_list **a);
void		b_rev_rotate_b(t_list **b);
void		b_rev_rotate_r(t_list **a, t_list **b);
void		b_rotate(t_list **a);
void		b_rotate_a(t_list **a);
void		b_rotate_b(t_list **b);
void		b_rotate_r(t_list **a, t_list **b);
void		b_swap(int *a, int *b);
void		b_swap_a(t_list *a);
void		b_swap_b(t_list *b);
void		b_swap_ss(t_list *a, t_list *b);
void		b_lstclear(t_list *lst, t_data *data);
void		b_bonus_norm(int n, int count, char **argv);
void		b_ft_sort_done_bonus(t_list **lst, int flag);
void		b_ft_sort_done_bonus(t_list **lst, int flag);
int			ft_app_input_two(char **arr, t_data *data, t_list **a, t_list **b);
int			ft_app_input(char **arr, t_data *data, t_list **a, t_list **b);
int			ft_command_input(t_list **a, t_list **b, t_data *data);
size_t		b_ft_strlen(const char *a);
char		*b_ft_strchr(const char *s, int c);
char		*b_ft_strjoin(char const *s1, char const *s2);
char		*b_ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
int			b_ft_strncmp(const char *c1, const char *c2, size_t n);
char		*b_ft_strrchr(const char *s, int c);
#endif