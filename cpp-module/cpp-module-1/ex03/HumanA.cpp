#include "HumanA.h"

HumanA::HumanA(const string name, Weapon& weapon) : Human(name) {
	_weapon = weapon;
}