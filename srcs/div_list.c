#include "push_swap.h"

void div_list(t_list **stack_A, t_list **stack_B, t_list **B_end, int *psc, int index)
{
    int tmp;
    int break_point;

    break_point = find_min_index(*stack_A) + (index * 5);
    while (find_min_index(*stack_A) + index < find_max_index(*stack_A) && find_min_index(*stack_A) + index < break_point)
    {
        tmp = find_min_index(*stack_A);
        while (check_index(*stack_A, tmp + index) == 1)
        {
            if (tmp + index > (*stack_A)->sort_index)
                ft_pb(stack_A, stack_B, B_end, psc);
            else
            {
                if (ra_or_rra(*stack_A, tmp + index) == 1)
                    ft_ra(stack_A, psc);
                else
                    ft_rra(stack_A, psc);
            }
        }
    }
}

void repeat_push_swap(t_list **stack_A, t_list **stack_B, t_list **B_end, int *push_swap_count, int ori_list_len)
{
    int tmp;
    int index;
    int break_point;

    index = length_of_list(*stack_A);
    while (check_sort_length(*stack_A, ori_list_len) == 0)
    {
        break_point = find_max_index(*stack_B);
        div_list(stack_A, stack_B, B_end, push_swap_count, (index / 5));
        while (find_max_index(*stack_B) > break_point)
            std_sort(stack_A, stack_B, B_end, push_swap_count);
        if (break_point == 0)
            ft_pa(stack_A, stack_B, push_swap_count);
        if (length_of_list(*stack_A) < ori_list_len)
            B_move_index(stack_A, stack_B, index, push_swap_count);
    }
}