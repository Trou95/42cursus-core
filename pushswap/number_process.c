#include "push_swap.h"

void    ft_numprocess(t_data *p, int ac, char **av, int index)
{
    int i;
    int j;
    int nm_start;

    ft_init(p);
    i = 0;
    while (++i < ac)
    {
        j = 0;
        nm_start = 0;
        while(av[i][j])
        {
            while(av[i][j] && av[i][j] == ' ')
                j++;
            nm_start = j;
            if(av[i][j] == '+' || av[i][j] == '-')
                j++;
            while(av[i][j] && av[i][j] != ' ')
                j++;
            ft_putnumber(p, &av[i][nm_start], index++);
            while(av[i][j] && av[i][j] == ' ')
                j++;
        }
    }
}

void    ft_putnumber(t_data *p, char *str, int index)
{
    int number;

    number = ft_atoi(str);
    if (ft_check_samenum(p->arr_b, number, index) == 1)
        ft_error("Error : Same number.");
    ft_array_push(p->arr_a,p->a_size++,number);
}