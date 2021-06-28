/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:00:34 by gejo              #+#    #+#             */
/*   Updated: 2021/06/23 00:32:19 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	div_list(t_list **stack_a, t_list **stack_b, t_list **b_end, int index)
{
	int tmp;
	int break_point;
	int push_swap_count;

	push_swap_count = 0;
	break_point = find_min_index(*stack_a) + (index * 5);
	while (find_min_index(*stack_a) + index < find_max_index(*stack_a) &&
					find_min_index(*stack_a) + index < break_point)
	{
		tmp = find_min_index(*stack_a);
		while (check_index(*stack_a, tmp + index) == 1)
		{
			if (tmp + index > (*stack_a)->sort_index)
				ft_pb(stack_a, stack_b, b_end, &push_swap_count);
			else
			{
				if (ra_or_rra(*stack_a, tmp + index) == 1)
					ft_ra(stack_a, &push_swap_count);
				else
					ft_rra(stack_a, &push_swap_count);
			}
		}
	}
	return (push_swap_count);
}

int	repeat_push_swap(t_list **stack_a, t_list **stack_b,
				t_list **b_end, int ori_list_len)
{
	int index;
	int break_point;
	int push_swap_count;

	push_swap_count = 0;
	index = length_of_clist(*stack_a);
	while (check_sort_length(*stack_a, ori_list_len) == 0)
	{
		break_point = find_max_index(*stack_b);
		push_swap_count += div_list(stack_a, stack_b, b_end, (index / 5));
		while (find_max_index(*stack_b) > break_point)
			std_sort(stack_a, stack_b, b_end, &push_swap_count);
		if (break_point == 0)
			ft_pa(stack_a, stack_b, &push_swap_count);
		if (length_of_clist(*stack_a) < ori_list_len)
			b_move_a_cindex(stack_a, stack_b, index, &push_swap_count);
	}
	return (push_swap_count);
}
