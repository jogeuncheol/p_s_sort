#include "push_swap.h"

void error_fn(t_list *list, t_list *stack_A)
{
    if (list != NULL)
        free_list(list);
    if (stack_A != NULL)
        free_nodes(stack_A);
    write(2, "Error\n", 6);
    exit(1);
}