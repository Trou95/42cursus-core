#include "utils.h"

t_list* ft_util_initlist(t_list* list)
{
	list = malloc(sizeof(t_list));
	if (!list)
		ft_util_msg(NULL);
	return (list);
}

int ft_util_msg(char* msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	else
		exit(1);
	return (0);
}

