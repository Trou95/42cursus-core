#include "push_swap.h"


int ft_check_shorted2(t_data *p)
{
    int i;

    i = 0;
    while (i < p->total_size - 1)
    {
        if (p->arr_a[i] > p->arr_a[i+1] )
            i++;
        else
            return (0);
    }
    return 1;
}

void ft_print(t_data *p_data)
{
     printf("A\tB\n");
        for(int i = 0; i < p_data->total_size; i++)
        {
            if(i < p_data->a_size)
                printf("%d\t",p_data->arr_a[i]);
            else 
                printf("\t");
            if(i < p_data->b_size)
                printf("%d",p_data->arr_b[i]);
            else 
                printf(" ");
            printf("\n");
        }
        
}

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

        //while(!ft_check_shorted2(&p_data))
            //ft_rotate(&p_data,'a');

        ft_print(&p_data);
       
       
    }
}