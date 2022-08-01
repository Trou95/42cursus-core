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

        ft_short_pivot(&p_data);
        ft_short_process(&p_data);

        printf("A\tB\n");
        for(int i = 0; i < p_data.total_size; i++)
        {
            if(i < p_data.a_size)
                printf("%d\t",p_data.arr_a[i]);
            else 
                printf("\t");
            if(i < p_data.b_size)
                printf("%d",p_data.arr_b[i]);
            else 
                printf(" ");
            printf("\n");
        }
       
    }
}