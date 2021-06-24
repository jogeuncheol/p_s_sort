/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:10:15 by gejo              #+#    #+#             */
/*   Updated: 2021/06/22 22:10:16 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **list, int *push_swap_count)
{
	int	tmp;

	tmp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->data = tmp;
	tmp = (*list)->sort_index;
	(*list)->sort_index = (*list)->next->sort_index;
	(*list)->next->sort_index = tmp;
	*push_swap_count = *push_swap_count + 1;
	write(1, "sa\n", 3);
}

void	ft_ra(t_list **list, int *push_swap_count)
{
	(*list) = (*list)->next;
	*push_swap_count = *push_swap_count + 1;
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **list, int *push_swap_count)
{
	(*list) = (*list)->prev;
	*push_swap_count = *push_swap_count + 1;
	write(1, "rra\n", 4);
}

void	ft_pb(t_list **stack_a, t_list **stack_b,
				t_list **b_end, int *push_swap_count)
{
	t_list	*tmp_node;

	tmp_node = (*stack_a)->next;
	(*stack_a)->next->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		(*stack_b) = *stack_a;
		(*stack_b)->next = *stack_a;
		(*stack_b)->prev = *stack_a;
		*b_end = *stack_b;
	}
	else
	{
		(*stack_b)->prev = *stack_a;
		(*stack_a)->next = *stack_b;
		(*stack_a)->prev = *b_end;
		(*b_end)->next = *stack_a;
		*stack_b = *stack_a;
	}
	*stack_a = tmp_node;
	*push_swap_count = *push_swap_count + 1;
	write(1, "pb\n", 3);
}
