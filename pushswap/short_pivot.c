#include "push_swap.h"

void ft_short_pivot(t_data *p)
{
    int res;

    while(p->a_size > 2)
    {
        res = ft_array_pivot(p->arr_a, p->a_size);
        printf("----- %d\n",p->a_size);
        for(int i = 0; i < p->a_size; i++)
            printf("%d\n",p->arr_a[i]);
        printf("-----\n");
        printf("res: %d\n",res);
        if(p->arr_a[p->a_size - 1] <= res)
            ft_push(p, 'b');
        else
            ft_rotate(p, 'a');
    }
}

int ft_array_pivot(int *arr, int size)
{
    int i;
    unsigned long long sum;

    i = 0;
    sum = 0;
    while(i < size)
        sum += arr[i++];
    return sum / size;
}
