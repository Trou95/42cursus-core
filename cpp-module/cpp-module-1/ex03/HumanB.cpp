#include "HumanB.h"

HumanB::HumanB(const string name) : Human(name) {

}

void HumanB::setWeapon(const Weapon& weapon) {
	_weapon = weapon;
}