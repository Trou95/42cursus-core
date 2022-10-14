#include "Zombie.h"

Zombie *Zombie::zombieHorde(int N, string name) {
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N ; ++i) {
		zombies[i].setName(name);
	}
	return zombies;
}