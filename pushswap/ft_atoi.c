#include "push_swap.h"

int ft_atoi(char *str)
{
    long result;
    int sign;

    result = 0;
    sign = 1;

    if (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -1;
    while (*str && *str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX)
            return ft_error("Error: ");
        if(result * sign < INT_MIN)
            return ft_error("Error: ");
        str++;
    }
    return ((int)result * sign);
}