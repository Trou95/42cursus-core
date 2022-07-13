#include "Weapon.h"


Weapon::Weapon(const string type) {
	this->type = type;
}

const string& Weapon::getType() {
	return type;
}

void Weapon::setType(const string type) {
	this->type = type;
}