
#include "utils.h"

long long ft_atoi(const char* str)
{
	long long val;
	int n;

	val = 0;
	n = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			n = -1;
	while (*str && ft_isdigit(*str))
		val = val * 10 + *str++ - 48;
	val = val * sign;
	if (val > INT_MAX || val < INT_MIN)
		return ft_util_msg(NULL);
	return (val);
}