#include "push_swap.h"

int ft_atoi(char *s)
{
    long result;
    int op;

    result = 0;
    op = 1;

    if (*s == '+' || *s == '-')
        if (*s++ == '-')
            op = -1;
    while (*s && *s >= '0' && *s <= '9')
    {
        result *= 10;
        result = result + (*s - '0');
        if (result * op > INT_MAX)
            return ft_error("Error: ");
        if(result * op < INT_MIN)
            return ft_error("Error: ");
        s++;
    }
    return ((int)result * op);
}