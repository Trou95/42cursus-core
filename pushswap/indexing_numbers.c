#include "push_swap.h"

void    indexing_numbers(t_psw *s)
{
    int tmp;
    int i;
    int j;
    int t;

    
    i = 0;
    t = 0;
    while (i < s->count)
    {
        j = 0;
        tmp = INT_MAX;
        while (j < s->count)
        {
            if (tmp > s->arr_a[j] && check_samenum(s->arr_c, s->arr_a[j], i) == 0)
                tmp = s->arr_a[j];
            j++;
        }
        s->arr_c[i++] = tmp;
    }
    i = 0;
    while (i < s->count)
    {
        printf("-------------sorted---\n %d\n", s->arr_c[i]);
        i++;
    }

}
