#include "push_swap.h"

t_list *circle_linked_list(int i, int list_len, t_list *list)
{
    t_list *node;
    t_list *head;
    t_list *prev;

    head = NULL;
    prev = NULL;
    while (++i < list_len - 10)
    {
        node = creat_node(list->data);
        if (node == NULL)
            return (head);
        if (head == NULL)
        {
            head = node;
            prev = node;
        }
        else
        {
            link_nodes(head, prev, node);
            prev = node;
            head->prev = node;
        }
        list = list->next;
    }
    return (head);
}

void single_linked_list(t_list **list, int nbr)
{
    t_list *head;
    t_list *new_node;

    head = NULL;
    new_node = NULL;
    if (*list == NULL)
    {
        *list = creat_node(nbr);
        if (*list == NULL)
            error_fn(*list, NULL);
    }
    else
    {
        head = *list;
        while ((*list)->next != NULL)
            *list = (*list)->next;
        new_node = creat_node(nbr);
        if (new_node == NULL)
            error_fn(*list, NULL);
        (*list)->next = new_node;
        *list = head;
    }
}

int length_of_list2(t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        i++;
        list = list->next;
    }
    return (i);
}