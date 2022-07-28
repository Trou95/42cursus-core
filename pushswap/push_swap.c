#include "push_swap.h"

int main(int ac, char **av)
{
    t_data  p_data;
    if (ac > 1)
    {
        p_data.total_size = ft_check_numbers(ac, av);
        ft_numprocess(&p_data, ac, av, 0);
        ft_is_shorted(&p_data);
        
    }
}