#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : DiamondTrap("Undefined") {

}

DiamondTrap::DiamondTrap(const string& name) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitpoints = 100;
	_energy = 50;
	_attackdamage = 30;
	cout << "DiamondTrap " << this->_name << " created " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) {
	*this = diamondtrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap) {
	if (this != &diamondtrap) {
		this->_name = diamondtrap._name;
		ClapTrap::_name = diamondtrap._name + "_clap_name";
		this->_hitpoints = diamondtrap._hitpoints;
		this->_energy = diamondtrap._energy;
		this->_attackdamage = diamondtrap._attackdamage;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	if (ScravTrap::_energy > 0 && FlagTrap::_hitpoints > 0)
		cout << "DiamondTrap " << _name << " Clapname " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}