#include "push_swap.h"

int ft_short_process(t_data *p)
{
    int i;
    int idx_a;
    int idx_b;
    int tmpidx_a;
    int count;

    i = -1;
    idx_a = 0;
    idx_b = 0;
    count = INT_MAX;
    while(++i < p->b_size)
    {
     if(count > ft_get_totalmove(p,i,&tmpidx_a))
     {
        count = ft_get_totalmove(p,i,&tmpidx_a);
        idx_a = tmpidx_a;
        idx_b = i;
     }
    }

    printf("Count: %d A: %d %d B: %d %d\n", count, p->arr_a[idx_a],idx_a,p->arr_b[idx_b],idx_b);
}

int ft_short_move(t_data *p,int index_a, int index_b)
{
  
}

int ft_get_totalmove(t_data *p,int index,int *index_a)
{
  int count;

  count = ft_abs(ft_get_movecount(p->b_size, index));
  if(index_a)
  {
     *index_a = ft_array_minidx(p->arr_a, p->a_size, p->arr_b[index]);
      if(*index_a == -1)
        return ft_error("Error: Total move");
      count += ft_abs(ft_get_movecount(p->a_size, *index_a));
  }
  return (count);
}

int ft_get_movecount(int size, int index)
{
    if(index == size - 1)
        return 0;
    if(index > size / 2)
        return ((size - 1) - index);
    return (-(index + 1));
}