/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fn1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:10:30 by gejo              #+#    #+#             */
/*   Updated: 2021/06/22 22:10:31 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_index(t_list *list)
{
	t_list	*tmp;
	int		max;

	if (list == NULL)
		return (0);
	if (list->next == NULL)
		return (list->sort_index);
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

int		find_min_index(t_list *list)
{
	t_list	*tmp;
	int		min;

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

int		find_max_data(t_list *list)
{
	t_list	*tmp;
	int		max;

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

int		find_max_order(t_list *list)
{
	t_list	*tmp;
	int		max_data;
	int		max_index;
	int		i;

	if (list == NULL || list->next == NULL)
		return (0);
	i = 0;
	max_data = list->data;
	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->data > max_data)
		{
			max_data = tmp->data;
			max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_index);
}

int		check_index(t_list *list, int index)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->prev->sort_index < index || tmp->sort_index < index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
