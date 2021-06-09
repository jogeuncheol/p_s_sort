#include "push_swap.h"

int is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int if_nbr(char *str, int *i, int *nbr_check)
{
    if (str[*i] >= '0' && str[*i] <= '9')
    {
        while (str[*i] >= '0' && str[*i] <= '9')
        {
            *nbr_check = 1;
            *i = *i + 1;
        }
    }
    else
    {
        if (is_nbr(str[*i - 1]) == 0 && str[*i - 1] != ' ')
            *nbr_check = 0;
        return (0);
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
        if (if_nbr(str, &i, &nbr_check) == 0)
            break;
    }
    if (nbr_check == 1)
        return (1);
    return (0);
}

int validity_check_argv(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i] != NULL)
    {
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