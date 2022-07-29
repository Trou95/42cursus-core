#include "push_swap.h"

int    ft_init(t_data *p)
{
    p->arr_a = malloc(sizeof(int) * p->total_size);
    if(!p->arr_a)
        return ft_error("Error: Allocation error A");
    p->arr_b = malloc(sizeof(int) * p->total_size);
    if (!p->arr_b)
        return ft_error("Error: Allocation error B");
    p->a_size = 0;
    p->b_size = 0;
}

void ft_fill(t_data *p)
{
    int i;

    i = 0;
    while(i < p->total_size)
    {
        ft_push(p,'a');
        p->arr_b[p->total_size - i - 1] = 0;
        i++;
    }
}