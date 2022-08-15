#include "checker.h"

void	try_steps(t_data *p, int *steps, int size, int i)
{
	while (++i < size)
	{
		if (steps[i] == 11)
			ft_swap(p, 'a');
		else if (steps[i] == 1)
			ft_swap(p, 'b');
		else if (steps[i] == 2)
			ft_swap(p, 'x');
		else if (steps[i] == 3)
			ft_push(p, 'a');
		else if (steps[i] == 4)
			ft_push(p, 'b');
		else if (steps[i] == 5)
			ft_rotate(p, 'a');
		else if (steps[i] == 6)
			ft_rotate(p, 'b');
		else if (steps[i] == 7)
			ft_rotate(p, 'x');
		else if (steps[i] == 8)
			ft_revrotate(p, 'a');
		else if (steps[i] == 9)
			ft_revrotate(p, 'b');
		else if (steps[i] == 10)
			ft_revrotate(p, 'x');
	}
}

int	rule_check(char *str, int **steps, int *size, int i)
{
	if (!ft_strncmp(str, "ss", 2) && i == 3)
		return (intjoin(steps, 2, size));
	else if (!ft_strncmp(str, "rrb", 3) && i == 4)
		return (intjoin(steps, 9, size));
	else if (!ft_strncmp(str, "rrr", 3) && i == 4)
		return (intjoin(steps, 10, size));
	else if (!ft_strncmp(str, "rra", 3) && i == 4)
		return (intjoin(steps, 8, size));
	else if (!ft_strncmp(str, "sa", 2) && i == 3)
		return (intjoin(steps, 11, size));
	else if (!ft_strncmp(str, "sb", 2) && i == 3)
		return (intjoin(steps, 1, size));
	else if (!ft_strncmp(str, "pa", 2) && i == 3)
		return (intjoin(steps, 3, size));
	else if (!ft_strncmp(str, "pb", 2) && i == 3)
		return (intjoin(steps, 4, size));
	else if (!ft_strncmp(str, "rr", 2) && i == 3)
		return (intjoin(steps, 7, size));
	else if (!ft_strncmp(str, "ra", 2) && i == 3)
		return (intjoin(steps, 5, size));
	else if (!ft_strncmp(str, "rb", 2) && i == 3)
		return (intjoin(steps, 6, size));
	return (ft_error("Error"));
}

void	ft_read(int **steps, int *size)
{
	char	*str;
	int		i;

	str = malloc(4);
	i = read(0, str, 4);
	while (i && rule_check(str, steps, size, i) != -200)
		i = read(0, str, 4);
	free(str);
}

int	intjoin(int **arr, int number, int *size)
{
	int	*temp;
	int	i;

	i = -1;
	if (*size == 0)
	{
		temp = (int *)malloc(sizeof(int));
		temp[0] = number;
	}
	else
	{
		temp = (int *)malloc(sizeof(int) * (*size) + 1);
		while (++i < *size)
			temp[i] = *((*arr) + i);
		temp[*size] = number;
	}
	if (*size > 0)
		free(*arr);
	*arr = temp;
	*size = *size + 1;
	return (1);
}

int	main(int ac, char **av)
{
	t_data	p_data;
	int		*steps;
	int		size;

	if (ac > 1)
	{
		size = 0;
		p_data.total_size = ft_check_numbers(ac, av);
		ft_numprocess(&p_data, ac, av);
		ft_read(&steps, &size);
		try_steps(&p_data, steps, size, -1);
		if (ft_check_sorted(&p_data))
			return (write(1, "OK\n", 3));
		else
			return (write(1, "KO\n", 3));
	}
}
