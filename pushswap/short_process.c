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
    printf("--------\n");
    printf("B Size: %d\n",p->b_size);
    printf("--------\n");
    while(p->b_size)
    {
      printf("Count: %d A: %d %d B: %d %d\n", count, p->arr_a[idx_a],idx_a,p->arr_b[idx_b],idx_b);
      ft_short_move(p,ft_get_movecount(p->a_size,idx_a),ft_get_movecount(p->b_size,idx_b));
    }
}

void ft_sort_fnhook(int count, void(*fn)(t_data*,char check), t_data* p, char check)
{
  while(count--)
    fn(p,check);
}

int ft_short_move(t_data *p,int index_a, int index_b)
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
      ft_sort_fnhook(ft_abs(index_b),&ft_revrotate,p,'b');
      ft_sort_fnhook(index_a,ft_rotate,p,'a');
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
  int tmp;

  count = ft_abs(ft_get_movecount(p->b_size, index));
  tmp = count;
  printf("CountB: %d ",count);
  if(index_a)
  {
     *index_a = ft_array_minidx(p->arr_a, p->a_size, p->arr_b[index]);
      if(*index_a == -1)
        return ft_error("Error: Total move");
      count += ft_abs(ft_get_movecount(p->a_size, *index_a));
      printf("CountA: %d\n",count - tmp);
      
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