#include "push_swap.h"

int main(int ac, char **av)
{
    t_psw   s;
    if (ac > 1)
    {
        s.count = check_numbers(ac, av);
        ft_allocatenumbers(&s);
        ft_numprocess(&s, ac, av, 0);
        ft_check_order(&s);
        indexing_numbers(&s);
        
    }
}