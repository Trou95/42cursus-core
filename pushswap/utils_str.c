#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	return (write(1, str, len));
}
// void	ft_print(t_data *p_data)
// {
// 	printf("A\tB\n");
// 		for(int i = 0; i < p_data->total_size; i++)
//         {
// 			if (i < p_data->a_size)
// 				printf("%d\t",p_data->arr_a[i]);
// 			else 
// 				printf("\t");
// 			if (i < p_data->b_size)
// 				printf("%d",p_data->arr_b[i]);
// 			else 
// 				printf(" ");
// 			printf("\n");
// 		}
// }
