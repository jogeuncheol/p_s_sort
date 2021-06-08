#include "push_swap.h"

int first_top_index(t_list *list, int index)
{
    int top_index;
    int list_len;
    int i;

    i = 0;
    list_len = length_of_list(list);
    while (i < list_len)
    {
        if (list->sort_index < index)
        {
            top_index = i;
            break;
        }
        list = list->next;
        i++;
    }
    return (top_index);
}

int first_bottom_index(t_list *list, int index)
{
    int bottom_index;
    int list_len;
    int i;

    i = 0;
    list_len = length_of_list(list);
    while (i < list_len)
    {
        if (list->sort_index < index)
        {
            bottom_index = i;
            break;
        }
        list = list->prev;
        i++;
    }
    return (bottom_index);
}

int ra_or_rra(t_list *list, int index)
{
    t_list *tmp;
    int top_index;
    int bottom_index;

    top_index = first_top_index(list, index);
    bottom_index = first_bottom_index(list, index);
    if (top_index < bottom_index)
        return (1);
    return (0);
}

int ft_atoi(char *str)
{
    int i;
	int ret;
	int sign;

	i = 0;
	ret = 0;
	sign = 0; // 0524 add sign initial
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		ret = ret * -1;
	return (ret);
}