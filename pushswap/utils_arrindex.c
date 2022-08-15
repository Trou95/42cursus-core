#include "push_swap.h"

void	ft_array_numidx(t_data *p)
{
	int	i;
	int	min;
	int	minindex;
	int	*temp;

	temp = malloc(sizeof(int) * p->total_size);
	i = -1;
	min = INT_MIN;
	while (++i < p->a_size)
	{
		minindex = ft_array_minidx(p->arr_a, p->a_size, min);
		min = p->arr_a[minindex];
		temp[minindex] = i;
	}
	free(p->arr_a);
	p->arr_a = temp;
}

int	ft_array_minidx(int *arr, size_t size, int start)
{
	size_t	i;
	int		second;

	i = -1;
	while (++i < size)
		if (arr[i] > start)
			second = i;
	i = -1;
	while (++i < size)
	{
		if (arr[i] > start && arr[i] < arr[second])
			second = i;
	}
	return (second);
}
