#include "push_swap.h"

void ft_sa(t_list **list, int *push_swap_count)
{
    int tmp;

    tmp = (*list)->data;
    (*list)->data = (*list)->next->data;
    (*list)->next->data = tmp;
    tmp = (*list)->sort_index;
    (*list)->sort_index = (*list)->next->sort_index;
    (*list)->next->sort_index = tmp;
    *push_swap_count = *push_swap_count + 1;
    write(1, "sa\n", 3);
}

void ft_ra(t_list **list, int *push_swap_count)
{
    (*list) = (*list)->next;
    *push_swap_count = *push_swap_count + 1;
    write(1, "ra\n", 3);
}

void ft_rra(t_list **list, int *push_swap_count)
{
    (*list) = (*list)->prev;
    *push_swap_count = *push_swap_count + 1;
    write(1, "rra\n", 4);
}

void ft_pb(t_list **stack_A, t_list **stack_B,
                t_list **B_end, int *push_swap_count)
{
    t_list *tmp_node;

    tmp_node = (*stack_A)->next;
    (*stack_A)->next->prev = (*stack_A)->prev;
	(*stack_A)->prev->next = (*stack_A)->next;
	if (*stack_B == NULL)
	{
		(*stack_B) = *stack_A;
		(*stack_B)->next = *stack_A;
		(*stack_B)->prev = *stack_A;
		*B_end = *stack_B;
	}
	else
	{
		(*stack_B)->prev = *stack_A;
		(*stack_A)->next = *stack_B;
		(*stack_A)->prev = *B_end;
		(*B_end)->next = *stack_A;
		*stack_B = *stack_A;
	}
	*stack_A = tmp_node;
    *push_swap_count = *push_swap_count + 1;
    write(1, "pb\n", 3);
}