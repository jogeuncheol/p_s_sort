/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:09:24 by gejo              #+#    #+#             */
/*   Updated: 2021/06/24 17:46:07 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_fn(t_list *list, t_list *stack_a)
{
	if (list != NULL)
		free_list(list);
	if (stack_a != NULL)
		free_nodes(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
