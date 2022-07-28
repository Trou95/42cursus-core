#include "ClapTrap.h"


int main(int ac, char**av)
{
	ClapTrap claptrap("Player 1");
	claptrap.attack("Player 2");
	claptrap.takeDamage(5);
	claptrap.beRepaired(2);
}