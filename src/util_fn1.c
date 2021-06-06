#include "push_swap.h"

int find_max_index(t_list *list)
{
    t_list *tmp;
    int max;

    if (list == NULL || list->next == NULL)
        return (0);
    tmp = list->next;
    max = list->sort_index;
    while (tmp != list)
    {
        if (max < tmp->sort_index)
            max = tmp->sort_index;
        tmp = tmp->next;
    }
    return (max);
}

int find_min_index(t_list *list)
{
    t_list *tmp;
    int min;

    if (list == NULL || list->next == NULL)
        return (0);
    tmp = list->next;
    min = list->sort_index;
    while (tmp != list)
    {
        if (min > tmp->sort_index)
            min = tmp->sort_index;
        tmp = tmp->next;
    }
    return (min);
}

int find_max_data(t_list *list)
{
    t_list *tmp;
    int max;

    if (list == NULL || list->next == NULL)
        return (0);
    tmp = list->next;
    max = list->data;
    while (tmp != list)
    {
        if (max < tmp->data)
            max = tmp->data;
        tmp = tmp->next;
    }
    return (max);
}

int check_index(t_list *list, int index)
{
    t_list *tmp;

    tmp = list->next;
    while (tmp != list)
    {
        if (tmp->prev->sort_index < index || tmp->sort_index < index)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}