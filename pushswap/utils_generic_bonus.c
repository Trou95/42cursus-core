#include "checker.h"

int	ft_init(t_data *p)
{
	p->arr_a = malloc(sizeof(int) * p->total_size);
	if (!p->arr_a)
		return (ft_error("Error: Allocation error A"));
	p->arr_b = malloc(sizeof(int) * p->total_size);
	if (!p->arr_b)
		return (ft_error("Error: Allocation error B"));
	p->a_size = 0;
	p->b_size = 0;
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX)
			return (ft_error("Error"));
		if (result * sign < INT_MIN)
			return (ft_error("Error"));
		str++;
	}
	return ((int)result * sign);
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_error(char *s)
{
	ft_putstr(s);
	ft_putstr("\n");
	exit(1);
	return (0);
}
