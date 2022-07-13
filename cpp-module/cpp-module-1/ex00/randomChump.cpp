#include "Zombie.h"

void randomChump(string name) {
	Zombie *z = newZombie(name);
	if (z == nullptr)
		return;
	z->announce();
	delete z;
}