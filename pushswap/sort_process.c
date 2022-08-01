#include "push_swap.h"

int ft_sort_process(t_data *p)
{
    int i;
    int idx_a;
    int idx_b;
    int tmpidx_a;
    int count;

    while(p->b_size)
    {
      i = 0;
      count = INT_MAX;
      while(i < p->b_size)
      {
       if(count > ft_get_totalmove(p,i,&tmpidx_a))
       {
         count = ft_get_totalmove(p,i,&tmpidx_a);
         idx_a = tmpidx_a;
         idx_b = i;
         printf("Count: %d %d %d\n",count,idx_a,idx_b);
       }
       i++;
      printf("Count %d %d %d\n",count,idx_a,idx_b);
     }
     printf("Count: %d , A: %d %d B: %d %d CountA:%d CountB: %d\n", count,p->arr_a[idx_a],idx_a,p->arr_b[idx_b],idx_b,ft_get_movecount(p->a_size,idx_a),ft_get_movecount(p->b_size,idx_b));
     ft_sort_move(p,ft_get_movecount(p->a_size,idx_a),ft_get_movecount(p->b_size,idx_b));
    }
}

void ft_sort_fnhook(int count, void(*fn)(t_data*, char), t_data* p, char check)
{
  int i = 0;
  while(i < count)
  {
    fn(p,check);
    i++;
  }
}

int ft_sort_move(t_data *p,int index_a, int index_b)
{
  ft_print(p);
  if(index_a > 0)
  {
    if(index_b > 0)
    {
      if(index_a < index_b)
      {
        ft_sort_fnhook(ft_abs(index_a),&ft_rotate,p,'x');
        ft_sort_fnhook(index_b - index_a, &ft_rotate,p,'b');
      }
      else
      {
        ft_sort_fnhook(ft_abs(index_b),&ft_rotate,p,'x');
        ft_sort_fnhook(index_a - index_b,&ft_rotate,p,'a');
      }
    }
    else
    {
      printf("3-");
      ft_sort_fnhook(ft_abs(index_b),&ft_revrotate,p,'b');
      ft_sort_fnhook(index_a,&ft_rotate,p,'a');
    }
  }
  else
  {
    if(index_b < 0)
    {
      if(index_a < index_b)
      {
        ft_sort_fnhook(ft_abs(index_b),&ft_revrotate,p,'x');
        ft_sort_fnhook(ft_abs(index_b - index_a), &ft_revrotate,p,'a');
      }
      else
      {
        ft_sort_fnhook(ft_abs(index_a),&ft_revrotate,p,'x');
        ft_sort_fnhook(ft_abs(index_a - index_b),&ft_revrotate,p,'b');
      }
    }
    else
    {
      ft_sort_fnhook(index_b,&ft_rotate,p,'b');
      ft_sort_fnhook(ft_abs(index_a),&ft_revrotate,p,'a');
    }
  }
  ft_push(p,'a');
}

int ft_get_totalmove(t_data *p,int index,int *index_a)
{
  int count;

  *index_a = ft_array_minidx(p->arr_a, p->a_size, p->arr_b[index]);
  count = ft_abs(ft_get_movecount(p->b_size, index));
  if(*index_a == -1)
    return ft_error("Error: Total move");
  count += ft_abs(ft_get_movecount(p->a_size, *index_a));
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