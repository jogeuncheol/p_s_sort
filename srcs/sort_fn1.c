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

void arr_sort(int *array, int len)
{
    int i;
    int j;
    int min;
    int tmp;

    i = 0;
    while (i < len - 1)
    {
        min = i;
        j = i + 1;
        while (j < len)
        {
            if (array[min] > array[j])
                min = j;
            j++;
        }
        tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
        i++;
    }
}

void pre_sort(t_list **list, int *array, int len)
{
    t_list *tmp;
    int i;

    arr_sort(array, len);
    tmp = *list;
    i = 0;
    while (i < len)
    {
        while ((*list)->data != array[i])
            (*list) = (*list)->next;
        (*list)->sort_index = i;
        i++;
    }
    *list = tmp;
}