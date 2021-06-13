#include "push_swap.h"

void std_sort(t_list **stack_A, t_list **stack_B,
                t_list **B_end, int *push_swap_count)
{
    if ((*stack_A)->data > (*stack_A)->next->data)
        ft_sa(stack_A, push_swap_count);
    else if ((*stack_A)->data > (*stack_A)->prev->data ||
                    (*stack_A)->next->data > (*stack_A)->prev->data)
        ft_rra(stack_A, push_swap_count);
    else
    {
        if (check_sort(*stack_A) == 1)
        {
            while (*stack_B != NULL &&
                            find_max_index(*stack_B) != (*stack_B)->sort_index)
            {
                if (length_of_list(*stack_B) / 2 > find_max_order(*stack_B))
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

int push_swap(int list_len, t_list **stack_A, int ori_list_len)
{
    int index;
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
        push_swap_count += div_list(stack_A, &stack_B, &stack_B_end, index);
    if (length_of_list(*stack_A) >= 50)
        push_swap_count += 
            repeat_push_swap(stack_A, &stack_B, &stack_B_end, ori_list_len);
    else
    {
        while (check_sort_length(*stack_A, list_len) == 0)
            std_sort(stack_A, &stack_B, &stack_B_end, &push_swap_count);
    }
    return (push_swap_count);
}

int main(int argc, char *argv[])
{
    t_list *stack_A;
    t_list *list;
    int A_len;
    int list_len;

    list = NULL;
    if (argc > 1)
    {
        if (validity_check_argv(argv) == 1 &&
            split_argv(argv, &list) == 1 && dup_check_numbers(list) == 1)
        {
            list_len = length_of_list2(list);
            stack_A = circle_linked_list(-1, list_len, list);
            A_len = length_of_list(stack_A);
            if (A_len != list_len)
                error_fn(list, stack_A);
            pre_sort(&stack_A, list, list_len);
            push_swap(list_len, &stack_A, A_len);
            free_list(list);
            free_nodes(stack_A);
        }
        else
            error_fn(list, NULL);
    }
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

void print_list2(t_list *list)
{
    while (list != NULL)
    {
        printf("data : %d\n", list->data);
        list = list->next;
    }
}
