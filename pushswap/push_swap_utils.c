#include "push_swap.h"

void ft_push(t_psw *s, char check)
{
    if(check == 'a')
    {
        ft_array_push(s->arr_a,s->a_size++,s->arr_b[s->b_size-- - 1]);
        ft_putstr("pa");
    }
    else if(check == 'b')
    {
        ft_array_push(s->arr_b, s->b_size++,s->arr_a[s->a_size-- - 1]);
        ft_putstr("pb");
    }
}

void ft_swap(t_psw *s, char check)
{
    if(check == 'a')
    {
        ft_array_swap(s->arr_a);
        ft_putstr("sa");
    }
    else if(check == 'b')
    {
        ft_array_swap(s->arr_b);
        ft_putstr("sb");
    }
    else if(check == 'x')
    {
        ft_array_swap(s->arr_a);
        ft_array_swap(s->arr_b);
        ft_putstr("ss");
    }
}

void ft_rotate(t_psw *s, char check)
{
    if(check == 'a')
    {
        ft_array_rotate(s->arr_a,s->a_size);
        ft_putstr("ra");
    }
    else if(check == 'b')
    {
        ft_array_rotate(s->arr_b, s->b_size);
        ft_putstr("rb");
    }
    else if(check == 'x')
    {
        ft_array_rotate(s->arr_a, s->a_size);
        ft_array_rotate(s->arr_b, s->b_size);
    }
}

void ft_revrotate(t_psw *s, char check)
{
    if(check == 'a')
    {
        ft_array_revrotate(s->arr_a, s->a_size);
        ft_putstr("rra");
    }
    else if(check == 'b')
    {
        ft_array_revrotate(s->arr_b, s->b_size);
        ft_putstr("rrb");
    }
    else if(check == 'x')
    {
        ft_array_revrotate(s->arr_a, s->a_size);
        ft_array_revrotate(s->arr_b, s->b_size);
    }
}
