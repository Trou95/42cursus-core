#include "ClapTrap.h"

ClapTrap::ClapTrap() : ClapTrap("Player 1") {

}

ClapTrap::ClapTrap(const string& name) {
	_name = name;
	_hitpoints = 10;
	_energy = 10;
	_attackdamage = 0;
	cout << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap) : ClapTrap(claptrap._name) {
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap) {
	if(this != claptrap) {
	 this->_name = claptrap._name;
	 this->_hitpoints = claptrap._hitpoints;
	 this->_energy = claptrap._energy;
	 this->_attackdamage = claptrap._attackdamage;
	}
	return *this;
}

void ClapTrap::attack(const string& target) {
	if (_energy > 0 && _hitpoints > 0) {
		_energy--;
		cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int damage) {
	_hitpoints -= damage;
	cout << "ClapTrap " << _name << " takes " << damage << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy > 0 && _hitpoints > 0) {
		_hitpoints += amount;
		_energy--;
		cout << "Claptrap " << _name << " restored " << amount << " hit points" << std::endl;
	}
}

ClapTrap::~ClapTrap() {
	cout << _name << " destroyed" << std::endl;
}

