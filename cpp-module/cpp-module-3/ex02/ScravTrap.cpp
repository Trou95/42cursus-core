#include "ScravTrap.h"

ScravTrap::ScravTrap() : ScravTrap("Player 1") {

}

ScravTrap::ScravTrap(const string& name) : ClapTrap(name)
{
	_name = name;
	_hitpoints = 100;
	_energy = 50;
	_attackdamage = 20;
	cout << "ScravTrap " << _name << " created" << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap& scravtrap) {
	*this = scravtrap;
}

ScravTrap& ScravTrap::operator=(const ScravTrap& scravtrap) {
	if (this != &scravtrap) {
		this->_name = scravtrap._name;
		this->_hitpoints = scravtrap._hitpoints;
		this->_energy = scravtrap._energy;
		this->_attackdamage = scravtrap._attackdamage;
	}
	return *this;
}

void ScravTrap::guardGate() {
	if(_energy > 0 && _hitpoints > 0)
		cout << "ScravTrap " << _name << " now in gate keepermode" << std::endl;
}

ScravTrap::~ScravTrap()
{
	cout << "Scravtrap " << _name << " destroy" << std::endl;
}