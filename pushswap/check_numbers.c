#include "push_swap.h"

int ft_check_numbers(int ac, char **av)
{
    int i;
    int j;
    int is_num;
    int c_total;

    i = 1;
    c_total = 0;
    while (i < ac)
    {
        if(!ft_strlen(av[i]))
            ft_error("Error: Empty argument");
        j = 0;
        while(av[i][j])
        { 
            is_num = 0;
            j += ft_check_number(&av[i][j],&is_num);
            if(is_num)
                c_total++;
        }
        i++;
    } 
    printf("Numbers: %d\n", c_total);
    return (c_total);
}

int ft_check_number(char* str, int* is_num)
{
    int i;

    i = 0;
    while(str[i] && str[i] == ' ')
        i++;
    if(str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] && str[i] != ' ')
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return (ft_error("Error: Invalıd value"));
        *is_num = ++i;
    }
    if(!*is_num)
        return (ft_error("Error: There is not number."));
    while(str[i] && str[i] == ' ')
        i++;
    return i;
}

int    ft_check_samenum(int *arr, int n, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if(arr[i] == n)
            return (1);
        i++;
    }
    return (0);
}

int ft_is_shorted(t_data *p)
{
    int i;

    i = 0;
    while (i < p->total_size)
    {
        if (p->arr_a[i] < p->arr_a[i+1] )
            i++;
        else
            return (0);
    }
    return (ft_error("Error: Already shorted"));
}

int ft_error(char *s)
{
    printf("%s\n", s);
    exit(1);
    return 0;
}