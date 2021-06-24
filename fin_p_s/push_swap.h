/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:09:52 by gejo              #+#    #+#             */
/*   Updated: 2021/06/23 00:32:05 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				data;
	int				sort_index;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list				*creat_node(int i);
t_list				*circle_linked_list(int i, int list_len, t_list *list);
void				link_nodes(t_list **h_node, t_list **p_node, t_list *node);
void				free_nodes(t_list *head);
int					length_of_list(t_list *list);

int					push_swap(int list_len, t_list **stack_a, int index);
void				std_sort(t_list **stack_a, t_list **stack_b,
									t_list **b_end, int *push_swap_count);

int					check_sort(t_list *list);
int					check_sort_length(t_list *list, int len);
void				data_swap(t_list **min, t_list **node);
void				pre_sort(t_list **stack_a, t_list *list, int len);
t_list				*list_sort(t_list *list);

void				ft_sa(t_list **list, int *push_swap_count);
void				ft_ra(t_list **list, int *push_swap_count);
void				ft_rra(t_list **list, int *push_swap_count);
void				ft_pb(t_list **stack_a, t_list **stack_b,
							t_list **b_end, int *push_swap_count);
void				ft_pa(t_list **stack_a, t_list **stack_b,
							int *push_swap_count);
void				ft_rb(t_list **stack_b, t_list **b_end,
							int *push_swap_count);
void				ft_rrb(t_list **stack_b, t_list **b_end,
							int *push_swap_count);
void				b_move_a_cindex(t_list **stack_a, t_list **stack_b,
							int index, int *push_swap_count);
t_list				*refresh_b(t_list *stack_b);

int					find_max_index(t_list *list);
int					find_min_index(t_list *list);
int					find_max_data(t_list *list);
int					find_max_order(t_list *list);
int					check_index(t_list *list, int index);
int					first_top_index(t_list *list, int index);
int					first_bottom_index(t_list *list, int index);
int					ra_or_rra(t_list *list, int index);

int					div_list(t_list **stack_a, t_list **stack_b,
							t_list **b_end, int index);
int					repeat_push_swap(t_list **stack_a, t_list **stack_b,
							t_list **b_end, int ori_list_len);

int					validity_check_argv(char **argv);
int					validity_check_nbr(char *str);
int					if_nbr(char *str, int *i, int *nbr_check);

int					split_argv(char **argv, t_list **list);
int					dup_check_numbers(t_list *list);
long				custom_atoi(char *argv, int *j);

void				single_linked_list(t_list **list, int nbr);
void				free_list(t_list *list);
int					length_of_list2(t_list *list);
int					is_nbr(char c);

void				error_fn(t_list *list, t_list *stack_a);

#endif
