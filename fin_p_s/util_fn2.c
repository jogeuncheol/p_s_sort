/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fn2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:10:35 by gejo              #+#    #+#             */
/*   Updated: 2021/06/23 00:25:50 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_top_index(t_list *list, int index)
{
	int	top_index;
	int	list_len;
	int	i;

	i = 0;
	top_index = 0;
	list_len = length_of_clist(list);
	while (i < list_len)
	{
		if (list->sort_index < index)
		{
			top_index = i;
			break ;
		}
		list = list->next;
		i++;
	}
	return (top_index);
}

static int	first_bottom_index(t_list *list, int index)
{
	int	bottom_index;
	int	list_len;
	int	i;

	i = 0;
	bottom_index = 0;
	list_len = length_of_clist(list);
	while (i < list_len)
	{
		if (list->sort_index < index)
		{
			bottom_index = i;
			break ;
		}
		list = list->prev;
		i++;
	}
	return (bottom_index);
}

int			ra_or_rra(t_list *list, int index)
{
	int		top_index;
	int		bottom_index;

	top_index = first_top_index(list, index);
	bottom_index = first_bottom_index(list, index);
	if (top_index < bottom_index)
		return (1);
	return (0);
}
