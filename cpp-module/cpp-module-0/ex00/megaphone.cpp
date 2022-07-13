#include <iostream>

int main(int ac, char** av)
{
	if (ac > 1) {
		for (int i = 1; i < ac; i++)
			for (int p = 0; av[i][p]; p++)
				std::cout << static_cast<char>(toupper(av[i][p]));
	}
	else std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}