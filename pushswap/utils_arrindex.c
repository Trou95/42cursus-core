#include "push_swap.h"

void ft_array_numidx(t_data *p)
{
    int i;
    int min;
    int minindex;

    i = -1;
    min = INT_MIN;
    while(++i < p->a_size)
    {
        minindex = ft_array_minidx(p->arr_a, p->a_size, min);
        min = p->arr_a[minindex] + 1;
        p->arr_a[minindex] = i;
    }
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