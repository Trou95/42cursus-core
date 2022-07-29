#ifndef _DIAMONDTRAP_H_
#define _DIAMONDTRAP_H_

#include "ScravTrap.h"
#include "FlagTrap.h"


class DiamondTrap : protected ScravTrap , protected FlagTrap{
public:

	DiamondTrap();
	DiamondTrap(const string& name);
	DiamondTrap(const DiamondTrap& diamondtrap);

	DiamondTrap& operator=(const DiamondTrap& diamondtrap);

	~DiamondTrap();

	using ClapTrap::attack;
	void whoAmI();

private:
	string _name;
};



#endif