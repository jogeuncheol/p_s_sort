#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

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
    int max_data;
}   t_index;

t_list *creat_node(int i);
void link_nodes(t_list *h_node, t_list *p_node, t_list *node);
t_list *circle_linked_list(int i, int count, int *array);
int length_of_list(t_list *list);
void free_nodes(t_list *head);


int push_swap(int argc, t_list **stack_A, int index);
void std_sort(t_list **stack_A, t_list **stack_B, t_list **B_end, int *push_swap_count);
void ft_putstr(char *str);

int check_sort(t_list *list);
int check_sort_length(t_list *list, int len);
void arr_sort(int *array, int len);
void pre_sort(t_list **list, int *array, int len);


void ft_sa(t_list **list, int *push_swap_count);
void ft_rra(t_list **list, int *push_swap_count);
void ft_pb(t_list **stack_A, t_list **stack_B, t_list **B_end, int *push_swap_count);
void ft_pa(t_list **stack_A, t_list **stack_B, int *push_swap_count);
void ft_rb(t_list **stack_B, t_list **B_end, int *push_swap_count);
void ft_rrb(t_list **stack_B, t_list **B_end, int *push_swap_count);
t_list *refresh_B(t_list *stack_B);
void B_move_index(t_list **stack_A, t_list **stack_B, int index, int *push_swap_count);

int find_max_index(t_list *list);
int find_min_index(t_list *list);
int find_max_data(t_list *list);
int check_index(t_list *list, int index);
int first_top_index(t_list *list, int index);
int first_bottom_index(t_list *list, int index);
int ra_or_rra(t_list *list, int index);
int ft_atoi(char *str);

void div_list();


#endif