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