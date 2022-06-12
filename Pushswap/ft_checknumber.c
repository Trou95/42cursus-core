
#include "utils/utils.h"

void ft_check_numbers(int ac, char** av)
{
	int i;
	int index;
	int bIsDigit;
	int number_count;

	i = 0;
	number_count = 0;
	while (i < ac)
	{
		index = 0;
		while (av[i][index])
		{
			bIsDigit = 0;
			ft_check_number(av[i][index], &index, &bIsDigit, 0);
			if (bIsDigit)
				number_count++;
		}
		i++;
	}
}

int ft_check_number(const char* str,int* i,int* bIsDigit,int type)
{
	int n;
	long long	val;
	int	bIsSign;

	bIsSign = 0;
	while (str[*i] && str[*i] == ' ')
		*i++;
	n = *i;
	if (str[*i] == '+' || str[*i] == '-')
	{
		*i++;
		bIsSign = 1;
	}
	while (str[*i] && str[*i] != ' ')
	{
		if (!ft_isdigit(str[*i++]))
			return ft_util_msg(NULL);
		*bIsDigit = 1;
	}
	if (!*bIsDigit && bIsSign)
		return ft_util_msg(NULL);
	if (type == 0)
		return 0;
	val = ft_atoi(str + n);
	return (val);
}