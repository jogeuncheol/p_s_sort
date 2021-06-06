#include "push_swap.h"

void ft_pa(t_list **stack_A, t_list **stack_B, int *push_swap_count)
{
    t_list *pop;
	t_list *A_end;

	pop = *stack_B;
	A_end = (*stack_A)->prev;
	(*stack_A)->prev = pop; // pop == *stack_B top -> stack_a top
	pop->next = *stack_A;
	pop->prev = A_end;
	A_end->next = pop;
	*stack_A = (*stack_A)->prev;
    *push_swap_count++;
    ft_putstr("pa\n");
}

void ft_rb(t_list **stack_B, t_list **B_end, int *push_swap_count)
{
    *B_end = *stack_B;
    (*stack_B) = (*stack_B)->next;
    *push_swap_count++;
    ft_putstr("rb\n");
}

void ft_rrb(t_list **stack_B, t_list **B_end, int *push_swap_count)
{
    *stack_B = (*stack_B)->prev;
    *B_end = (*stack_B)->prev;
    *push_swap_count++;
    ft_putstr("rrb\n");
}

t_list *refresh_B(t_list *stack_B)
{
    if (stack_B->prev == NULL && stack_B->next == NULL)
        return (NULL);
    stack_B->next->prev = stack_B->prev;
    stack_B->prev->next = stack_B->next;
    stack_B = stack_B->next;
    if (stack_B == stack_B->prev && stack_B == stack_B->next)
    {
        stack_B->prev = NULL;
        stack_B->next = NULL;
    }
    return (stack_B);
}

void B_move_index(t_list **stack_A, t_list **stack_B, int index, int *push_swap_count)
{
    int i;
    t_list *tmp_list;
    
    i = 0;
    while (i < index)
    {
        tmp_list = refresh_B(*stack_B);
        ft_pa(stack_A, stack_B, push_swap_count);
        *stack_B = tmp_list;
        i++;
    }
}