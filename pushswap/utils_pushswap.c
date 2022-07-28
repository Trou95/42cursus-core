#include "push_swap.h"

void ft_push(t_data *p, char check)
{
    if(check == 'a')
    {
        ft_array_push(p->arr_a,p->a_size++,p->arr_b[p->b_size-- - 1]);
        ft_putstr("pa");
    }
    else if(check == 'b')
    {
        ft_array_push(p->arr_b, p->b_size++,p->arr_a[p->a_size-- - 1]);
        ft_putstr("pb");
    }
}

void ft_swap(t_data *p, char check)
{
    if(check == 'a')
    {
        ft_array_swap(p->arr_a, p->a_size);
        ft_putstr("sa");
    }
    else if(check == 'b')
    {
        ft_array_swap(p->arr_b, p->b_size);
        ft_putstr("sb");
    }
    else if(check == 'x')
    {
        ft_array_swap(p->arr_a, p->a_size);
        ft_array_swap(p->arr_b, p->b_size);
        ft_putstr("ss");
    }
}

void ft_rotate(t_data *p, char check)
{
    if(check == 'a')
    {
        ft_array_rotate(p->arr_a,p->a_size);
        ft_putstr("ra");
    }
    else if(check == 'b')
    {
        ft_array_rotate(p->arr_b, p->b_size);
        ft_putstr("rb");
    }
    else if(check == 'x')
    {
        ft_array_rotate(p->arr_a, p->a_size);
        ft_array_rotate(p->arr_b, p->b_size);
    }
}

void ft_revrotate(t_data *p, char check)
{
    if(check == 'a')
    {
        ft_array_revrotate(p->arr_a, p->a_size);
        ft_putstr("rra");
    }
    else if(check == 'b')
    {
        ft_array_revrotate(p->arr_b, p->b_size);
        ft_putstr("rrb");
    }
    else if(check == 'x')
    {
        ft_array_revrotate(p->arr_a, p->a_size);
        ft_array_revrotate(p->arr_b, p->b_size);
    }
}
