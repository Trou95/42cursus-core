#include "push_swap.h"


int main(int ac, char **av)
{
    t_data  p_data;
    if (ac > 1)
    {
        p_data.total_size = ft_check_numbers(ac, av);
        ft_numprocess(&p_data, ac, av, 0);
        ft_check_shorted(&p_data);

        ft_array_numidx(&p_data);
        ft_fill(&p_data);

        ft_short_pivot(&p_data);

         for(int i = 0; i < p_data.a_size; i++)
            printf("%d\n",p_data.arr_a[i]);
       
    }
}