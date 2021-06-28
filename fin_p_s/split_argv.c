/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:10:07 by gejo              #+#    #+#             */
/*   Updated: 2021/06/24 18:14:32 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			dup_check_numbers(t_list *list)
{
	t_list	*i;
	t_list	*j;
	int		data;

	i = list;
	while (i->next != NULL)
	{
		j = i->next;
		data = i->data;
		while (j != NULL)
		{
			if (data == j->data)
			{
				return (0);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static long	custom_atoi(char *argv, int *j)
{
	long	nbr;
	long	sign;

	nbr = 0;
	sign = 1;
	while (argv[*j] == ' ')
		*j = *j + 1;
	if (argv[*j] == '+' || argv[*j] == '-')
	{
		if (argv[*j] == '-')
			sign = -1;
		*j = *j + 1;
	}
	while (argv[*j] >= '0' && argv[*j] <= '9')
	{
		nbr = (nbr * 10) + (argv[*j] - '0');
		*j = *j + 1;
	}
	return (nbr * sign);
}

int			split_argv(char **argv, t_list **list)
{
	int		i;
	int		j;
	long	nbr;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (validity_check_nbr(argv[i]) == 1)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				nbr = custom_atoi(argv[i], &j);
				if (argv[i][j - 1] == ' ')
					break ;
				if (nbr > 2147483647 || nbr < -2147483648 ||
						(argv[i][j] != ' ' && argv[i][j] != '\0'))
					return (0);
				single_linked_list(list, nbr);
			}
		}
		else
			return (0);
	}
	return (1);
}
