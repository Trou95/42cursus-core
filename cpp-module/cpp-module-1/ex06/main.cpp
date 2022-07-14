#include "Harl.h"


int main(int ac, char**av)
{
	if (ac == 1)
	{
		Harl harl;

		harl.complain(av[1]);
	}
}