#include "push_swap.h"

t_list *creat_node(int i)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        return (NULL);
    node->data = i;
    node->sort_index = 0;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void link_nodes(t_list **h_node, t_list **p_node, t_list *node)
{
    (*p_node)->next = node;
    node->next = *h_node;
    node->prev = *p_node;
    *p_node = node;
    (*h_node)->prev = node;
}

int length_of_list(t_list *list)
{
	int len;
	t_list *tmp;

    if (list == NULL)
        return (0);
	len = 1;
	tmp = list->next;
	while (tmp != list)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void free_list(t_list *list)
{
    t_list *tmp;

    while (list != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

void free_nodes(t_list *head)
{
    int count;
    t_list *tmp;

    tmp = head->next;
    while (tmp != head)
    {
        tmp = tmp->next;
        free(tmp->prev);
        tmp->prev = NULL;
    }
    free(tmp);
    tmp = NULL;
}