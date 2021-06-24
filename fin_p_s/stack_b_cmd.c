/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:10:22 by gejo              #+#    #+#             */
/*   Updated: 2021/06/23 01:48:37 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b, int *push_swap_count)
{
	t_list	*pop;
	t_list	*a_end;
	t_list	*tmp_list;

	tmp_list = refresh_b(*stack_b);
	pop = *stack_b;
	a_end = (*stack_a)->prev;
	(*stack_a)->prev = pop;
	pop->next = *stack_a;
	pop->prev = a_end;
	a_end->next = pop;
	*stack_a = (*stack_a)->prev;
	*push_swap_count = *push_swap_count + 1;
	*stack_b = tmp_list;
	write(1, "pa\n", 3);
}

void	ft_rb(t_list **stack_b, t_list **b_end, int *push_swap_count)
{
	*b_end = *stack_b;
	*stack_b = (*stack_b)->next;
	*push_swap_count = *push_swap_count + 1;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **stack_b, t_list **b_end, int *push_swap_count)
{
	*stack_b = (*stack_b)->prev;
	*b_end = (*stack_b)->prev;
	*push_swap_count = *push_swap_count + 1;
	write(1, "rrb\n", 4);
}

t_list	*refresh_b(t_list *stack_b)
{
	if (stack_b->prev == NULL && stack_b->next == NULL)
		return (NULL);
	stack_b->next->prev = stack_b->prev;
	stack_b->prev->next = stack_b->next;
	stack_b = stack_b->next;
	if (stack_b == stack_b->prev && stack_b == stack_b->next)
	{
		stack_b->prev = NULL;
		stack_b->next = NULL;
	}
	return (stack_b);
}

void	b_move_a_cindex(t_list **stack_a, t_list **stack_b,
				int index, int *push_swap_count)
{
	int		i;

	i = 0;
	while (i < index && *stack_b != NULL)
	{
		ft_pa(stack_a, stack_b, push_swap_count);
		i++;
	}
}
