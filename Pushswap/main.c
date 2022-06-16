
#include "utils/utils.h"


int main(int ac, char** av)
{
	if (ac > 1)
	{
		t_list *list;
		ft_put_arr(list, ac, av + 1);
	}
}

void ft_put_arr(t_list* list, int ac, char** av)
{
	list = ft_util_initlist(list);

}