#include "Zombie.h"

Zombie::Zombie(const string name) {
	_name = name;
}

void Zombie::announce(void) {
	cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	cout << _name << " Deleted" << std::endl;
}