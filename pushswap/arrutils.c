#include "push_swap.h"

int    ft_allocatenumbers(t_psw *s)
{
    s->arr_a = malloc(sizeof(int) * s->count);
    if(!s->arr_a)
        return ft_error("Error: Allocation error A");
    s->arr_b = malloc(sizeof(int) * s->count);
    if (!s->arr_b)
        return ft_error("Error: Allocation error B");
    s->arr_c = malloc(sizeof(int) * s->count);
    if (!s->arr_c)
        return ft_error("Error: Allocation error C");

}

void    ft_numprocess(t_psw *s, int ac, char **av, int index)
{
    int i;
    int j;
    int nm_start;


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
            ft_putnumber(s, &av[i][nm_start], index++);
            while(av[i][j] && av[i][j] == ' ')
                j++;
        }
    } 
    for (int i = 0; i < s->count; i++)
        printf("%d\n", s->arr_a[i]);
}

int    check_samenum(int *s, int n, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if(s[i] == n)
            return (1);
        i++;
    }
    return (0);
}

void    ft_putnumber(t_psw *s, char *str, int index)
{
    int number;

    number = ft_atoi(str);
    if (check_samenum(s->arr_a, number, index) == 1)
    {
        ft_error("Error : Same number.");
    }
    s->arr_a[index] = number;
}

int ft_check_order(t_psw *s)
{
    int i;

    i = 0;
    while (i < s->count)
    {
        if (s->arr_a[i] < s->arr_a[i+1] )
            i++;
        else
            return (0);            
    }
    return (ft_error("It is already order."));
}

void ft_array_push(int *arr, size_t size, int value)
{
   arr[size] = value;
}

void ft_array_swap(int *arr, size_t size)
{
    int tmp;

    if(size-- < 2)
        return;
    tmp = arr[size];
    arr[size] = arr[size - 1];
    arr[size - 1] = tmp;
}

void ft_array_rotate(int *arr, size_t size)
{
    int tmp;

    size--;
    tmp = arr[size];
    while(size > 0)
        arr[size--] = arr[size - 1];
    arr[0] = tmp;
}

void ft_array_revrotate(int *arr, size_t size)
{
    size_t i;
    int tmp;

    tmp = arr[0];
    i = 1;
    while(i < size)
        arr[i++ - 1] = arr[i];
    arr[size - 1] = tmp;
}

