#include "FlagTrap.h"

FlagTrap::FlagTrap() : FlagTrap("Undefined") {

}

FlagTrap::FlagTrap(const string& name) : ClapTrap(name)
{
	_name = name;
	_hitpoints = 100;
	_energy = 100;
	_attackdamage = 30;
	cout << "FlagTrap " << _name << " created" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& flagtrap) {
	*this = flagtrap;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& flagtrap) {
	if (this != &flagtrap) {
		this->_name = flagtrap._name;
		this->_hitpoints = flagtrap._hitpoints;
		this->_energy = flagtrap._energy;
		this->_attackdamage = flagtrap._attackdamage;
	}
	return *this;
}

void FlagTrap::highFivesGuys() {
	if (_energy > 0 && _hitpoints > 0)
		cout << "FlagTrap " << _name << " high five guys" << std::endl;
}


FlagTrap::~FlagTrap()
{
	cout << "FlagTrap " << _name << " destroy" << std::endl;
}