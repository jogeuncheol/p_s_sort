/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fn2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:09:38 by gejo              #+#    #+#             */
/*   Updated: 2021/06/22 22:09:40 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		length_of_clist(t_list *list)
{
	int		len;
	t_list	*tmp;

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

int		length_of_slist(t_list *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = NULL;
		list = tmp;
	}
}

void	free_nodes(t_list *head)
{
	t_list	*tmp;

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
