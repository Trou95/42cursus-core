#include "push_swap.h"

int ft_array_numidx(t_data *p)
{
    int i;
    int *tmp;
    int min;
    int minindex;

    tmp = malloc(sizeof(int) * p->b_size);
    if(!tmp)
        return ft_error("Error: Allocation fail");
    i = -1;
    min = INT_MIN;
    while(++i < p->b_size)
    {
        minindex = ft_array_minidx(p->arr_b, p->b_size, min);
        tmp[minindex] = i;
        min = p->arr_b[minindex] + 1;
    }
    return 0;
}

int ft_array_minidx(int *arr, size_t size, int start)
{
    int i;
    int n;
    int minindex;

    i = 0;
    minindex = -1;
    while(i < size)
    {
        if(arr[i] >= start)
        {
            n = -1;
            minindex = i;
            while(++n < size)
                if(arr[n] < arr[minindex] && arr[n] >= start)
                    minindex = n;
            break;
        }
        i++;
    }
    return minindex;
}
