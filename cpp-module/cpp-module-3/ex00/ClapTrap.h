#ifndef _CLAPTRAP_H_
#define _CLAPTRAP_H_

#include <iostream>
#include <string>

using std::cout;
using std::string;


class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const string& name);

	ClapTrap(const ClapTrap& claptrap);

	~ClapTrap();

	void attack(const string& target);
	void takeDamage(unsigned int damage);
	void beRepaired(unsigned int amount);

	ClapTrap& operator=(const ClapTrap& claptrap);

private:
	string _name;
	unsigned _hitpoints;
	unsigned _energy;
	unsigned _attackdamage;
};



#endif