#include "push_swap.h"

void    ft_numprocess(t_data *p, int ac, char **av, int index)
{
    int i;
    int j;
    int nm_start;

    ft_init(p);
    i = 0;
    while (++i < ac)
    {
        j = 0;
        nm_start = 0;
        while(av[i][j])
        {
            while(av[i][j] && av[i][j] == ' ')
                j++;
            nm_start = j;
            if(av[i][j] == '+' || av[i][j] == '-')
                j++;
            while(av[i][j] && av[i][j] != ' ')
                j++;
            ft_putnumber(p, &av[i][nm_start], index++);
            while(av[i][j] && av[i][j] == ' ')
                j++;
        }
    }
}

void    ft_putnumber(t_data *p, char *str, int index)
{
    int number;

    number = ft_atoi(str);
    if (ft_check_samenum(p->arr_b, number, index) == 1)
        ft_error("Error : Same number.");
    ft_array_push(p->arr_b,p->b_size++,number);
}


void ft_array_push(int *arr, int size, int value)
{
   arr[size] = value;
}

void ft_array_swap(int *arr, int size)
{
    int tmp;

    if(size-- < 2)
        return;
    tmp = arr[size];
    arr[size] = arr[size - 1];
    arr[size - 1] = tmp;
}

void ft_array_rotate(int *arr, int size)
{
    int tmp;

    size--;
    tmp = arr[size];
    while(size > 0)
        arr[size--] = arr[size - 1];
    arr[0] = tmp;
}

void ft_array_revrotate(int *arr, int size)
{
    size_t i;
    int tmp;

    tmp = arr[0];
    i = 1;
    while(i < size)
        arr[i++ - 1] = arr[i];
    arr[size - 1] = tmp;
}

