#include "push_swap.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void set_array(int *array, int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        array[i] = ft_atoi(argv[i + 1]);
        i++;
    }
}

void std_sort(t_list **stack_A, t_list **stack_B, t_list **B_end, int *push_swap_count)
{
    t_list *tmp_list;

    if ((*stack_A)->data > (*stack_A)->next->data)
        ft_sa(stack_A, push_swap_count);
    else if ((*stack_A)->data > (*stack_A)->prev->data || (*stack_A)->next->data > (*stack_A)->prev->data)
        ft_rra(stack_A, push_swap_count);
    else
    {
        if (check_sort(*stack_A) == 1)
        {
            while (*stack_B != NULL || find_max_index(*stack_B) != (*stack_B)->sort_index)
            {
                if (length_of_list(*stack_B) / 2 > find_max_index(*stack_B))
                    ft_rb(stack_B, B_end, push_swap_count);
                else
                    ft_rrb(stack_B, B_end, push_swap_count);
            }
            ft_pa(stack_A, stack_B, push_swap_count);
        }
        else
            ft_pb(stack_A, stack_B, B_end, push_swap_count);
    }
}

int push_swap(int argc, t_list **stack_A, int index)
{
    int tmp;
    int push_swap_count;
    t_list *stack_B;
    t_list *stack_B_end;

    stack_B = NULL;
    stack_B_end = NULL;
    push_swap_count = 0;
    if (check_sort(*stack_A) == 1)
        return (0);
    if (length_of_list(*stack_A) >= 100)
        div_list();
    else
    {
        while (check_sort_length(*stack_A, argc - 1) == 0)
            std_sort(stack_A, &stack_B, &stack_B_end, &push_swap_count);
    }
    return (push_swap_count);
}

int main(int argc, char *argv[])
{
    t_list *stack_A;
    int *array;
    int index;
    int count;

    count = 0;
    if (argc > 1)
    {
        array = (int *)malloc(sizeof(int) * (argc - 1));
        set_array(array, argc, argv);
        stack_A = circle_linked_list(-1, argc - 1, array);
        pre_sort(&stack_A, array, argc - 1);
        index = length_of_list(stack_A) / 5;
        count = push_swap(argc, &stack_A, index);
        free(array);
        free_nodes(stack_A);
    }
    else
        write(1, "error\n", 6);
    return (0);
}