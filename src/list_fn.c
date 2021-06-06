#include "push_swap.h"

t_list *creat_node(int i)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    node->data = i;
    node->prev = NULL;
    node->next = NULL; 
    return (node);
}

void link_nodes(t_list *h_node, t_list *p_node, t_list *node)
{
    p_node->next = node;
    node->next = h_node;
    node->prev = p_node;
}

t_list *circle_linked_list(int i, int count, int *array)
{
    t_list *node;
    t_list *head;
    t_list *prev;

    head = NULL;
    prev = NULL;
    while (++i < count)
    {
        node = creat_node(array[i]);
        if (head == NULL)
        {
            head = node;
            prev = node;
            node->next = node;
            node->prev = node;
        }
        else
        {
            link_nodes(head, prev, node);
            prev = node;
            head->prev = node;
        }
    }
    return (head);
}

int length_of_list(t_list *list)
{
	int len;
	t_list *tmp;

	len = 1;
	tmp = list->next;
	while (tmp != list)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
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