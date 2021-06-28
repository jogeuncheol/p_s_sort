/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fn1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:15:04 by gejo              #+#    #+#             */
/*   Updated: 2021/06/24 18:00:38 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*creat_node(int i)
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

void	link_nodes(t_list **h_node, t_list **p_node, t_list *node)
{
	(*p_node)->next = node;
	node->next = *h_node;
	node->prev = *p_node;
	*p_node = node;
	(*h_node)->prev = node;
}

t_list	*circle_linked_list(int i, int list_len, t_list *list)
{
	t_list	*node;
	t_list	*head;
	t_list	*prev;

	head = NULL;
	prev = NULL;
	while (++i < list_len)
	{
		node = creat_node(list->data);
		if (node == NULL)
			return (head);
		if (head == NULL)
		{
			head = node;
			prev = node;
			node->next = node;
			node->prev = node;
		}
		else
			link_nodes(&head, &prev, node);
		list = list->next;
	}
	return (head);
}

void	single_linked_list(t_list **list, int nbr)
{
	t_list	*head;
	t_list	*new_node;

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
