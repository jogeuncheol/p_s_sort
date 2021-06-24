/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:09:44 by gejo              #+#    #+#             */
/*   Updated: 2021/06/24 18:13:37 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	std_sort(t_list **stack_a, t_list **stack_b,
				t_list **b_end, int *push_swap_count)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_sa(stack_a, push_swap_count);
	else if ((*stack_a)->data > (*stack_a)->prev->data ||
					(*stack_a)->next->data > (*stack_a)->prev->data)
		ft_rra(stack_a, push_swap_count);
	else
	{
		if (check_sort(*stack_a) == 1)
		{
			while (*stack_b != NULL &&
							find_max_index(*stack_b) != (*stack_b)->sort_index)
			{
				if (length_of_list(*stack_b) / 2 > find_max_order(*stack_b))
					ft_rb(stack_b, b_end, push_swap_count);
				else
					ft_rrb(stack_b, b_end, push_swap_count);
			}
			ft_pa(stack_a, stack_b, push_swap_count);
		}
		else
			ft_pb(stack_a, stack_b, b_end, push_swap_count);
	}
}

int		push_swap(int list_len, t_list **stack_a, int ori_list_len)
{
	int		index;
	int		push_swap_count;
	t_list	*stack_b;
	t_list	*stack_b_end;

	stack_b = NULL;
	stack_b_end = NULL;
	push_swap_count = 0;
	index = ori_list_len / 5;
	if (check_sort(*stack_a) == 1)
		return (0);
	if (length_of_list(*stack_a) >= 100)
		push_swap_count += div_list(stack_a, &stack_b, &stack_b_end, index);
	if (length_of_list(*stack_a) >= 50)
		push_swap_count +=
			repeat_push_swap(stack_a, &stack_b, &stack_b_end, ori_list_len);
	else
	{
		while (check_sort_length(*stack_a, list_len) == 0)
			std_sort(stack_a, &stack_b, &stack_b_end, &push_swap_count);
	}
	return (push_swap_count);
}

int		main(int argc, char *argv[])
{
	int		a_len;
	int		list_len;
	t_list	*stack_a;
	t_list	*list;

	list = NULL;
	if (argc > 1)
	{
		if (validity_check_argv(argv) == 1 &&
			split_argv(argv, &list) == 1 && dup_check_numbers(list) == 1)
		{
			list_len = length_of_list2(list);
			stack_a = circle_linked_list(-1, list_len, list);
			a_len = length_of_list(stack_a);
			if (a_len != list_len)
				error_fn(list, stack_a);
			pre_sort(&stack_a, list, list_len);
			push_swap(list_len, &stack_a, a_len);
			free_list(list);
			free_nodes(stack_a);
		}
		else
			error_fn(list, NULL);
	}
	return (0);
}
