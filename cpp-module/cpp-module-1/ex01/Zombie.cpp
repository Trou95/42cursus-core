#include "Zombie.h"

void Zombie::announce(void) {
	cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const string name) {
	_name = name;
}

Zombie::~Zombie() {
	cout << _name << " Deleted" << std::endl;
}