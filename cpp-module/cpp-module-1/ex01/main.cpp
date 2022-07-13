#include "Zombie.h"

int main()
{
	Zombie* zombies = zombieHorde(5, "Zombie");
	if (zombies != nullptr)
		delete[] zombies;
}