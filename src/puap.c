#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int data;
    int sort_index;
    struct s_list *prev;
    struct s_list *next;
}   t_list;

typedef struct s_index
{
    int list_len;
    int max_index;
    int max;
}   t_index;

typedef struct s_status
{
    char cmd;
}   t_status;

void print_array(int argc, int *array);
void print_list(int argc, t_list *head);

t_list *creat_node(int i)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    node->data = i;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void first_link_node(t_list *p_node, t_list *node)
{
    p_node->next = node;
    node->next = p_node;
    p_node->prev = node;
    node->next = p_node;
}

void link_nodes(t_list *h_node, t_list *p_node, t_list *node)
{
    p_node->next = node;
    node->next = h_node;
    node->prev = p_node;
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

void set_array(int *array, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		// printf("argv : %s\n", argv[i + 1]);
		array[i] = ft_atoi(argv[i + 1]);
		// printf("array[%d] : %d\n", i, array[i]);
		i++;
	}
}

void arr_sort(int *array, int len)
{
	int i;
	int j;
	int min;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
		i++;
	}
}

void pre_sort(t_list **list, int *array, int len)
{
	t_list *tmp;
	int i;

	tmp = *list;
	arr_sort(array, len);
	i = 0;
	while (i < len)
	{
		while ((*list)->data != array[i])
		{
			(*list) = (*list)->next;
		}
		(*list)->sort_index = i;
		i++;
	}
	*list = tmp;
}

int check_sort(t_list *head)
{
	t_list *tmp;

	tmp = head->next;
	while (tmp != head)
	{
		if (tmp->prev->data > tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int check_sort_length(t_list *head, int len)
{ // len == mid_data (100num : 20, 500num : 100)
	int i;

	i = 0;
	head = head->next;
	while (i < len - 1)
	{
		if (head->prev->data > head->data)
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}

t_list *refresh_b(t_list *b)
{
	// printf("b->prev b b->next : %p | %p | %p\n", b->prev, b, b->next);
	if (b->prev == NULL && b->next == NULL)
	{
		return (NULL);
	}
	b->next->prev = b->prev;
	b->prev->next = b->next;
	b = b->next;
	if (b == b->prev && b == b->next)
	{
		b->prev = NULL;
		b->next = NULL;
	}
	return (b);
}

t_list *push_a(t_list *stack_a, t_list *stack_b)
{
	t_list *pop;
	t_list *a_end;

	pop = stack_b;
	a_end = stack_a->prev;
	stack_a->prev = pop; // pop == stack_b top -> stack_a top
	pop->next = stack_a;
	pop->prev = a_end;
	a_end->next = pop;
	stack_a = stack_a->prev;
	printf("pa\n");
	return (stack_a);
}

int list_find_min(t_list *head)
{
	int idx;
	int min;
	int min_idx;
	t_list *tmp;

	min = head->data;
	idx = 0;
	tmp = head->next;
	while (head != tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			min_idx = idx;
		}
		tmp = tmp->next;
		idx++;
	}
	return (idx);
}

t_index *stack_b_find_max(t_list *stack_b)
{
	t_index *find_max;
	t_list *tmp;
	int i;

	i = 0;
	find_max = (t_index *)malloc(sizeof(t_index));
	find_max->list_len = 0;
	find_max->max_index = 0;
	find_max->max = stack_b->data;
	tmp = stack_b->next;
	if (tmp == NULL)
	{
		return (find_max);
	}
	while (tmp != stack_b)
	{
		find_max->list_len++;
		tmp = tmp->next;
	}
	find_max->list_len++;
	tmp = stack_b->next;
	while (tmp != stack_b)
	{
		if (find_max->max < tmp->data)
		{
			find_max->max = tmp->data;
			find_max->max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (find_max);
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

int find_max( t_list *list)
{
	t_list *tmp;
	int max;

	if (list == NULL || list->next == NULL)
		return (0);
	tmp = list->next;
	max = list->sort_index;
	while (tmp != list)
	{
		if (max < tmp->sort_index)
		{
			max = tmp->sort_index;
		}
		tmp = tmp->next;
	}
	return (max);
}
int find_min(t_list *list)
{
	t_list *tmp;
	int min;

	tmp = list->next;
	min = list->sort_index;
	while (tmp != list)
	{
		if (min > tmp->sort_index)
		{
			min = tmp->sort_index;
		}
		tmp = tmp->next;
	}
	return (min);
}

int check_mid_data(t_list *list, int mid_data)
{
	t_list *tmp;

	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->prev->sort_index < mid_data || tmp->sort_index < mid_data)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int ra_or_rra(t_list *list, int mid_data) // return 1 == ra, 0 == rra
{
	t_list *tmp;
	int top_idx;
	int bottom_idx;
	int list_len;
	int i;

	i = 0;
	list_len = length_of_list(list);
	tmp = list;
	while (i < list_len)
	{
		if (tmp->sort_index < mid_data)
		{
			top_idx = i;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	//tmp = tmp->prev;
	tmp = list;
	while (i < list_len)
	{
		if (tmp->sort_index < mid_data)
		{
			bottom_idx = i;
			break;
		}
		tmp = tmp->prev;
		i++;
	}
	if (top_idx < bottom_idx)
	{
		return (1); // ra
	}
	return (0); // rra
}

void push_b(t_list **stack_a, t_list **stack_b, t_list **stack_b_end)
{
    t_list *tmp_node;
    tmp_node = (*stack_a)->next;
	(*stack_a)->next->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		printf("stack_b == NULL\n");
		*stack_b = *stack_a;
		(*stack_b)->next = *stack_a;
		(*stack_b)->prev = *stack_a;
		*stack_b_end = *stack_b;
	}
	else
	{
	    printf("stack_b != NULL\n");
		(*stack_b)->prev = *stack_a;
		(*stack_a)->next = *stack_b;
		(*stack_a)->prev = *stack_b_end;
		(*stack_b_end)->next = *stack_a;
		*stack_b = *stack_a;
	}
	*stack_a = tmp_node;
}

void stack_b_move_mid_data(t_list **head, t_list **stack_b, int mid_data)
{
	int i;
	t_list *tmp_list;

	i = 0;
	while (i < mid_data)
	{
		tmp_list = refresh_b(*stack_b);
		*head = push_a(*head, *stack_b);
		*stack_b = tmp_list;
		i++;
	}
}

int repeat_push_swap(t_list **head, int mid_data, int break_point)
{
    int tmp;
    int push_swap_count;
    t_list *stack_b;
    t_list *stack_b_end;
    t_list *tmp_node;

    tmp_node = NULL;
    stack_b = NULL;
    stack_b_end = NULL;
    push_swap_count = 0;
    // while (length_of_list(*head) > (mid_data * 5))
	// while (check_sort_length(*head, mid_data * 5) == 0)
	printf("break_point : %d\n", break_point);
	while (find_min(*head) + mid_data < find_max(*head) && find_min(*head) + mid_data < break_point)
    {
		// if (check_sort_length(*head, mid_data * 5) == 1)// || find_min(*head) + mid_data < break_point)
		// 	break;
        printf("find_min + mid_data : %d\n", find_min(*head) + mid_data);
		tmp = find_min(*head);
		while (check_mid_data(*head, tmp + mid_data) == 1)
		{
			if (tmp + mid_data > (*head)->sort_index)
			{
       	    	push_b(head, &stack_b, &stack_b_end);
       	    	push_swap_count++;
				printf("half pb : %d\n", push_swap_count);
				// print_list(1, *head);
       		}
			else
			{
				if (ra_or_rra(*head, tmp + mid_data) == 1)
				{
					*head = (*head)->next;
       	        	push_swap_count++;
					printf("half ra : %d\n", push_swap_count);
				}
				else
				{
					*head = (*head)->prev;
					push_swap_count++;
					printf("half rra : %d\n", push_swap_count);
				}
       	     //push_swap_count++;
			}
    	}
    }
	// print_list(1, *head);
    // print_list(1, stack_b);
    while (stack_b != NULL)
	{
		if ((*head)->data > (*head)->next->data)
		{
			tmp = (*head)->data;
			(*head)->data = (*head)->next->data;
			(*head)->next->data = tmp;
			tmp = (*head)->sort_index;
			(*head)->sort_index = (*head)->next->sort_index;
			(*head)->next->sort_index = tmp;
			printf("sa : %d\n", push_swap_count);
		}
		else if ((*head)->data > (*head)->prev->data)
		{
			*head = (*head)->prev;
			printf("rra : %d\n", push_swap_count);
		}
		else if ((*head)->next->data > (*head)->prev->data)
		{
			*head = (*head)->prev;
			printf("rra : %d\n", push_swap_count);
		}
		else // push b (a -> b)
		{
			if (check_sort(*head) == 1)// && find_max(argc, array, stack_b) < (*head)->data)
			{
				// push a (b -> a)
				while (stack_b != NULL)
				{
					t_index *b_max = stack_b_find_max(stack_b);
					if (b_max->max == stack_b->data)
					{
						free(b_max);
						break;
					}
					if (b_max->list_len / 2 > b_max->max_index)
					{
						stack_b_end = stack_b; // 05_26 fix
						stack_b = stack_b->next;
						printf("rb : %d | data : %d\n", push_swap_count, stack_b->prev->data);
					}
					else // 05_26 add 100 numbers count 1456
					{
						stack_b = stack_b->prev;
						stack_b_end = stack_b->prev;
						printf("rrb : %d | data : %d\n", push_swap_count, stack_b->next->data);
					}
					push_swap_count++;
					free(b_max);
				}
				if (tmp_node == NULL)
				{
					stack_b = NULL;
					printf("tmp_node == NULL\n");
				}
				if (tmp_node != NULL)
				{
					tmp_node = refresh_b(stack_b);
					if (stack_b->next != NULL && stack_b->data < stack_b->next->data)
					{
						tmp = stack_b->data;
						stack_b->data = stack_b->next->data;
						stack_b->next->data = tmp;
						tmp = stack_b->sort_index;
						stack_b->sort_index = stack_b->next->sort_index;
						stack_b->next->sort_index = tmp;
						printf("sb : %d\n", push_swap_count);
						push_swap_count++;
						continue;
					}
					*head = push_a(*head, stack_b);
					stack_b = tmp_node;
					printf("stack A top data : %d\n", (*head)->data);
					//print_list(argc, *head);
				}
			}
			else // push b (a -> b)
			{
				tmp_node = (*head)->next;
				(*head)->next->prev = (*head)->prev;
				(*head)->prev->next = (*head)->next;
				if (stack_b == NULL)
				{
					printf("stack_b == NULL\n");
					stack_b = *head;
					stack_b->next = *head;
					stack_b->prev = *head;
					stack_b_end = stack_b;
				}
				else
				{
					printf("stack_b != NULL\n");
					stack_b->prev = *head;
					(*head)->next = stack_b;
					(*head)->prev = stack_b_end;
					stack_b_end->next = *head;
					stack_b = *head;
				}
				*head = tmp_node;
				printf("only pb : %d\n", push_swap_count);
			}
		}
		push_swap_count++;
	}
	printf("push_swap_count : %d", push_swap_count);
	return (push_swap_count);
}

int push_swap(int argc, t_list **head, int mid_data)
{ // head == stack_A
    int tmp;
    int push_swap_count;
    t_list *tmp_node;
    t_list *stack_b;
    t_list *stack_b_end;

    tmp_node = NULL;
    stack_b = NULL;
    stack_b_end = NULL;
    push_swap_count = 0;
	tmp = mid_data;
	printf("mid_data : %d | argc : %d\n", mid_data, argc);
	printf("--------------stack_a\n");
	print_list(argc, *head);
    if (check_sort(*head) == 1)
        return (0);
//		while (check_sort(*head) != 1){
	if (length_of_list(*head) >= 100){
	while (find_min(*head) + mid_data < find_max(*head))// argc - 1)
	{
		printf("find_min + mid_data : %d\n", find_min(*head) + mid_data);
		tmp = find_min(*head);
		while (check_mid_data(*head, tmp + mid_data) == 1 && argc - 1 >= 100)
		{
			if (tmp + mid_data > (*head)->sort_index)
			{
       	    	push_b(head, &stack_b, &stack_b_end);
       	    	push_swap_count++;
				printf("half pb : %d\n", push_swap_count);
       		}
			else
			{
				if (ra_or_rra(*head, tmp + mid_data) == 1)
				{
					*head = (*head)->next;
       	        	push_swap_count++;
					printf("half ra : %d\n", push_swap_count);
				}
				else
				{
					*head = (*head)->prev;
					push_swap_count++;
					printf("half rra : %d\n", push_swap_count);
				}
       	     //push_swap_count++;
			}
    	}
		// mid_data = mid_data + tmp;
	}
	}
	printf("--------------stack_a\n");
	print_list(argc, *head);
	printf("--------------stack_b\n");
    print_list(argc, stack_b);
	printf("======================set stack B==========================\n");
	printf("lengthof list : %d\n", length_of_list(*head));
	// mid_data = tmp;

	if (length_of_list(*head) >= 100)
	{ // 수정해야함.
		push_swap_count += repeat_push_swap(head, 20, find_min(*head) + 100);
//		push_swap_count += repeat_push_swap(head, length_of_list(*head) / 5);
//		push_swap_count += push_swap(101, head, 20);
		if (length_of_list(*head) < argc - 1)
		{
			stack_b_move_mid_data(head, &stack_b, mid_data);
			push_swap_count += mid_data;
		}
		printf("length_of_list head : %d\n", length_of_list(*head));
		print_list(argc, *head);
    	print_list(argc, stack_b);
		push_swap_count += repeat_push_swap(head, 20, find_min(*head) + 100);
		if (length_of_list(*head) < argc - 1)
		{
			stack_b_move_mid_data(head, &stack_b, mid_data);
			push_swap_count += mid_data;
		}
		printf("length_of_list head : %d\n", length_of_list(*head));
		print_list(argc, *head);
    	print_list(argc, stack_b);
		push_swap_count += repeat_push_swap(head, 20, find_min(*head) + 100);
		if (length_of_list(*head) < argc - 1)
		{
			stack_b_move_mid_data(head, &stack_b, mid_data);
			push_swap_count += mid_data;
		}
		printf("length_of_list head : %d\n", length_of_list(*head));
		print_list(argc, *head);
    	print_list(argc, stack_b);
		push_swap_count += repeat_push_swap(head, 20, find_min(*head) + 100);
		if (length_of_list(*head) < argc - 1)
		{
			stack_b_move_mid_data(head, &stack_b, mid_data);
			push_swap_count += mid_data;
		}
		printf("length_of_list head : %d\n", length_of_list(*head));
		print_list(argc, *head);
    	print_list(argc, stack_b);
		push_swap_count += repeat_push_swap(head, 20, find_min(*head) + 100);
	}
	else
	{
		// while (check_sort_length(*head, argc - 1) == 0)
		// {
		//while (stack_b != NULL)
		while (check_sort_length(*head, argc - 1) == 0)
		{
			if ((*head)->data > (*head)->next->data)
			{
				tmp = (*head)->data;
				(*head)->data = (*head)->next->data;
				(*head)->next->data = tmp;
				tmp = (*head)->sort_index;
				(*head)->sort_index = (*head)->next->sort_index;
				(*head)->next->sort_index = tmp;
				printf("sa : %d\n", push_swap_count);
			}
			else if ((*head)->data > (*head)->prev->data)
			{
				*head = (*head)->prev;
				printf("rra : %d\n", push_swap_count);
			}
			else if ((*head)->next->data > (*head)->prev->data)
			{
				*head = (*head)->prev;
				printf("rra : %d\n", push_swap_count);
			}
			else // push b (a -> b)
			{
				if (check_sort(*head) == 1)// && find_max(argc, array, stack_b) < (*head)->data)
				{
					// push a (b -> a)
					while (stack_b != NULL)
					{
						t_index *b_max = stack_b_find_max(stack_b);
						if (b_max->max == stack_b->data)
						{
							free(b_max);
							break;
						}
						if (b_max->list_len / 2 > b_max->max_index)
						{
							stack_b_end = stack_b; // 05_26 fix
							stack_b = stack_b->next;
							printf("rb : %d | data : %d\n", push_swap_count, stack_b->prev->data);
						}
						else // 05_26 add 100 numbers count 1456
						{
							stack_b = stack_b->prev;
							stack_b_end = stack_b->prev;
							printf("rrb : %d | data : %d\n", push_swap_count, stack_b->next->data);
						}
						push_swap_count++;
						free(b_max);
					}
					if (tmp_node == NULL)
					{
						stack_b = NULL;
						printf("tmp_node == NULL\n");
					}
					if (tmp_node != NULL)
					{
						tmp_node = refresh_b(stack_b);
						if (stack_b->next != NULL && stack_b->data < stack_b->next->data)
						{
							tmp = stack_b->data;
							stack_b->data = stack_b->next->data;
							stack_b->next->data = tmp;
							tmp = stack_b->sort_index;
							stack_b->sort_index = stack_b->next->sort_index;
							stack_b->next->sort_index = tmp;
							printf("sb : %d\n", push_swap_count);
							push_swap_count++;
							continue;
						}
						*head = push_a(*head, stack_b);
						stack_b = tmp_node;
						printf("stack A top data : %d\n", (*head)->data);
						//print_list(argc, *head);
					}
				}
				else // push b (a -> b)
				{
					tmp_node = (*head)->next;
					(*head)->next->prev = (*head)->prev;
					(*head)->prev->next = (*head)->next;
					if (stack_b == NULL)
					{
						printf("stack_b == NULL\n");
						stack_b = *head;
						stack_b->next = *head;
						stack_b->prev = *head;
						stack_b_end = stack_b;
					}
					else
					{
						printf("stack_b != NULL\n");
						stack_b->prev = *head;
						(*head)->next = stack_b;
						(*head)->prev = stack_b_end;
						stack_b_end->next = *head;
						stack_b = *head;
					}
					*head = tmp_node;
					printf("only pb : %d\n", push_swap_count);
				}
			}
			push_swap_count++;
		}
		// print_list(argc, *head);
    	// print_list(argc, stack_b);
		if (length_of_list(*head) != argc - 1)
		{
			stack_b_move_mid_data(head, &stack_b, mid_data);
			push_swap_count += mid_data;
		}
		// else
		// 	break;
		//if (stack_b != NULL)
		//}
	}
	print_list(argc, *head);
    print_list(argc, stack_b);
    return (push_swap_count);
}

int main(int argc, char *argv[])
{
	int *array;
	t_list *head;
	int mid_data;
	int count;

    count = 0;
	if (argc > 1) // push_swap _test_
	{
		array = (int *)malloc(sizeof(int) * (argc - 1));
		set_array(array, argc, argv);
		head = circle_linked_list(-1, argc - 1, array);
		pre_sort(&head, array, argc - 1);
		//mid_data = (find_min(head) + find_max(head)) + 1 / 5;
		mid_data = length_of_list(head) / 5;
		count = push_swap(argc, &head, mid_data);
	}
	printf("push_swap count : %d\n", count);
	if (argc > 1)
	{
		// print_list(argc, head);
		free(array);
		free_nodes(head);
	}
	return (0);
}

void print_array(int argc, int *array)
{
	printf("------------print array----------\n");
	for (int i = 0; i < argc - 1; i++)
	{
		printf("array[%d] : %d\n", i, array[i]);
	}
}

void print_list(int argc, t_list *head)
{
	t_list *tmp;

	if (head == NULL || head->next == NULL) return;
	printf("------------circle linked list----------\n");
	tmp = head->prev;
	int i = 0;
	while (tmp != head)	// while (i++ < argc - 2)
	{
		printf("| %-5d <- | data : %5d, idx : %5d | -> %5d | addr : %p\n", head->prev->data, head->data, head->sort_index, head->next->data, head);
		head = head->next;
	}
	printf("| %-5d <- | data : %5d, idx : %5d | -> %5d | addr : %p\n", head->prev->data, head->data, head->sort_index, head->next->data, head);
}