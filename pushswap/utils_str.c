#include "push_swap.h"

size_t ft_strlen(char * str)
{
    size_t i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}