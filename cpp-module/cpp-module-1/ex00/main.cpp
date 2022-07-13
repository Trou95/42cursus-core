#include "Zombie.h"

int main()
{
	Zombie *z = newZombie("Zombie");
	if (z != nullptr) {
		z->announce();
		delete z;
	}
	randomChump("Zombie2");
}