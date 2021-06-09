#include "push_swap.h"

int check_sort_length(t_list *list, int len)
{
    int i;

    i = 0;
    list = list->next;
    while (i < len - 1)
    {
        if (list->prev->data > list->data)
            return (0);
        list = list->next;
        i++;
    }
    return (1);
}

int check_sort(t_list *list)
{
    t_list *tmp;

    tmp = list->next;
    while (tmp != list)
    {
        if (tmp->prev->data > tmp->data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void data_swap(t_list **min, t_list **node)
{
    int tmp;

    tmp = (*min)->data;
    (*min)->data = (*node)->data;
    (*node)->data = tmp;
}

t_list *list_sort(t_list *list, int len)
{
    t_list *head;
    t_list *min;
    t_list *node;

    head = list;
    while (head->next != NULL)
    {
        node = head->next;
        min = head;
        while (node != NULL)
        {
            if (min->data > node->data)
            {
                min = node;
            }
            node = node->next;
        }
        data_swap(&min, &head);
        head = head->next;
    }
    return (list);
}

void pre_sort(t_list **stack_A, t_list *list, int len)
{
    t_list *tmp;
    int i;

    list = list_sort(list, len);
    tmp = *stack_A;
    i = 0;
    while (i < len)
    {
        while (tmp->data != list->data)
        {
            tmp = tmp->next;
        }
        tmp->sort_index = i;
        list = list->next;
        i++;
    }
}