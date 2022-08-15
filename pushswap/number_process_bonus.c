#include "checker.h"

void	ft_numprocess(t_data *p, int ac, char **av)
{
	int	i;
	int	j;
	int	nm_start;

	ft_init(p);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		nm_start = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			nm_start = j;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] && av[i][j] != ' ')
				j++;
			ft_putnumber(p, &av[i][nm_start]);
			while (av[i][j] && av[i][j] == ' ')
				j++;
		}
	}
}

void	ft_putnumber(t_data *p, char *str)
{
	int	number;

	number = ft_atoi(str);
	if (ft_check_samenum(p->arr_a, number,
			p->total_size - p->a_size, p->total_size) == 1)
		ft_error("Error");
	ft_array_push(p->arr_a, (p->total_size - 1) - p->a_size++, number);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (idx < n && s1[idx])
	{
		if (s1[idx] && s1[idx] == s2[idx])
		{
			while (s1[idx] && s1[idx] == s2[idx] && idx < n)
				idx++;
		}
		else
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	}
	return (0);
}
