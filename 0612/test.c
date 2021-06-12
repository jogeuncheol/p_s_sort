#include "push_swap.h"

void print_list(t_list *head)
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

void print_list2(t_list *list)
{
    while (list != NULL)
    {
        printf("data : %d\n", list->data);
        list = list->next;
    }
}

int is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int validity_check_argv(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i] != NULL)
    {
        printf("argv[%d] : [%s]\n", i, argv[i]);
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] >= '0' && argv[i][j] <= '9')
                j++;
            else if (argv[i][j] == '+' || argv[i][j] == '-')
                j++;
            else if (argv[i][j] == ' ')
                j++;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

int validity_check_nbr(char *str)
{
    int i;
    int nbr_check;

    i = 0;
    nbr_check = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '+' || str[i] == '-')
            i++;
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                nbr_check = 1;
                i++;
            }
        }
        else
        {
            if (is_nbr(str[i - 1]) == 0 && str[i - 1] != ' ')
                nbr_check = 0;
            break;
        }
    }
    if (nbr_check == 1)
        return (1);
    return (0);
}

void single_linked_list(t_list **list, long nbr)
{
    t_list *head;
    t_list *new_node;

    if (*list == NULL)
        *list = creat_node(nbr);
    else
    {
        head = *list;
        while ((*list)->next != NULL)
            *list = (*list)->next;
        new_node = creat_node(nbr);
        (*list)->next = new_node;
        *list = head;
    }
}

int split_argv(int argc, char **argv, t_list **list)
{
    int i;
    int j;
    long nbr;
    int sign;
    int arr_index;

    arr_index = 0;
    sign = 1;
    i = 1;
    while (argv[i] != NULL)
    {
        if (validity_check_nbr(argv[i]) == 1)
        {
            printf("check_nbr OK\n");
            j = 0;
            while (argv[i][j] != '\0')
            {
                nbr = 0;
                while (argv[i][j] == ' ')
                    j++;
                if (argv[i][j] == '+' || argv[i][j] == '-')
                {
                    if (argv[i][j] == '-')
                        sign = -1;
                    j++;
                }
                while (argv[i][j] >= '0' && argv[i][j] <= '9')
                {
                    nbr = (nbr * 10) + (argv[i][j] - '0');
                    j++;
                }
                if (argv[i][j - 1] == ' ')
                    break;
                nbr = nbr * sign;
                printf("nbr : %ld\n", nbr);
                if (nbr > 2147483647 || nbr < -2147483648)
                    return (0);
                single_linked_list(list, nbr);
                sign = 1;
            }
        }
        else
        {
            return (0);
        }
        i++;
    }
    return (1);
}

void error_fn()
{
    printf("error\n");
}

void free_list(t_list *list)
{
    t_list *tmp;

    while (list->next != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    free(list);
    list = NULL;
}

int length_of_list2(t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        i++;
        list = list->next;
    }
    return (i);
}

void data_swap(t_list **min, t_list **node)
{
    int tmp;

    tmp = (*min)->data;
    (*min)->data = (*node)->data;
    (*node)->data = tmp;
}

t_list *list_sort(t_list *list, int len)
{
    t_list *head;
    t_list *min;
    t_list *node;

    head = list;
    while (head->next != NULL)
    {
        node = head->next;
        min = head;
        while (node != NULL)
        {
            if (min->data > node->data)
            {
                min = node;
            }
            node = node->next;
        }
        data_swap(&min, &head);
        head = head->next;
    }
    return (list);
}

void pre_sort2(t_list **stack_A, t_list *list, int len)
{
    t_list *tmp;
    int i;

    list = list_sort(list, len);
    printf("list_sort\n");
    print_list2(list);
    tmp = *stack_A;
    i = 0;
    while (i < len)
    {
        while (tmp->data != list->data)
        {
            tmp = tmp->next;
        }
        tmp->sort_index = i;
        list = list->next;
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_list *stack_A;
    t_list *list;

    list = NULL;
    if (argc > 1 && validity_check_argv(argc, argv) == 1)
    {
        if (split_argv(argc, argv, &list) == 1)
        {
            printf("valid_argv\n");
            print_list2(list);
            stack_A = circle_linked_list2(-1, length_of_list2(list), list);
            print_list(stack_A);
            pre_sort2(&stack_A, list, length_of_list2(list));
            print_list(stack_A);
            free_list(list);
            free_nodes(stack_A);
        }
        else
            error_fn();
        
    }
    else
        printf("invalid_argv\n");
    return (0);
}