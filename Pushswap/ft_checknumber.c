
#include "utils/utils.h"

void ft_check_numbers(int ac, char** av)
{
	int i;
	int index;

	i = 0;
	while (i < ac)
	{
		index = 0;
		while (av[i][index])
			index = ft_check_number(av[i][index],0,0,0);
		i++;
	}
}

int ft_check_number(const char* str,int i,int bIsDigit,int bIsSign)
{
	int n;
	long long	val;

	while (str[i] && str[i] == ' ')
		i++;
	n = i;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		bIsSign = 1;
	}
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i++]))
			return ft_util_msg(NULL);
		bIsDigit = 1;
	}
	if (!bIsDigit && bIsSign)
		return ft_util_msg(NULL);
	val = ft_atoi(str + n);
	if (val > INT_MAX || val < INT_MIN)
		return ft_util_msg(NULL);
	return (i);
}