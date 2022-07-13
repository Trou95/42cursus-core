#include "Zombie.h"

Zombie* zombieHorde(int n, string name) {
	if (n > 0) {
		Zombie* zombies = new Zombie[n];
		if (zombies != nullptr) {
			for (int i = 0; i < n; i++) {
				zombies[i].setName(name);
				zombies[i].announce();
			}
		}
		return zombies;
	}
	return nullptr;
}
