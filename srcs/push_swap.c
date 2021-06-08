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

    if ((*stack_A)->sort_index > (*stack_A)->next->sort_index)
        ft_sa(stack_A, push_swap_count);
    else if ((*stack_A)->sort_index > (*stack_A)->prev->sort_index || (*stack_A)->next->sort_index > (*stack_A)->prev->sort_index)
        ft_rra(stack_A, push_swap_count);
    else
    {
        if (check_sort(*stack_A) == 1)
        {
            while (*stack_B != NULL && find_max_index(*stack_B) != (*stack_B)->sort_index)
            {
                if (length_of_list(*stack_B) / 2 > find_max_order(*stack_B))
                    ft_rb(stack_B, B_end, push_swap_count);
                else
                    ft_rrb(stack_B, B_end, push_swap_count);
            }
            if (tmp_list != NULL)
            {
                tmp_list = refresh_B(*stack_B);
                ft_pa(stack_A, stack_B, push_swap_count);
                *stack_B = tmp_list;
            }
        }
        else
            ft_pb(stack_A, stack_B, B_end, push_swap_count);
    }
}

int push_swap(int argc, t_list **stack_A, int ori_list_len)
{
    int index;
    int tmp;
    int push_swap_count;
    t_list *stack_B;
    t_list *stack_B_end;

    stack_B = NULL;
    stack_B_end = NULL;
    push_swap_count = 0;
    index = ori_list_len / 5;
    if (check_sort(*stack_A) == 1)
        return (0);
    if (length_of_list(*stack_A) >= 100)
        div_list(stack_A, &stack_B, &stack_B_end, &push_swap_count, index);
    if (length_of_list(*stack_A) >= 100)
        repeat_push_swap(stack_A, &stack_B, &stack_B_end, &push_swap_count, ori_list_len);
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
        index = length_of_list(stack_A);
        count = push_swap(argc, &stack_A, index);
        // print_list(stack_A);
        free(array);
        free_nodes(stack_A);
    }
    else
        write(1, "error\n", 6);
    // printf("p_s_c : %d\n", count);
    return (0);
}

void print_list(t_list *head)
{
	t_list *tmp;

	if (head == NULL || head->next == NULL) return;
	printf("------------circle linked list----------\n");
	tmp = head->prev;
	int i = 0;
	while (tmp != head)	// while (i++ < argc - 2)
	{
		printf("| %-5d <- | data : %5d, idx : %5d | -> %5d | addr : %p\n", head->prev->data, head->data, head->sort_index, head->next->data, head);
		head = head->next;
	}
	printf("| %-5d <- | data : %5d, idx : %5d | -> %5d | addr : %p\n", head->prev->data, head->data, head->sort_index, head->next->data, head);
}