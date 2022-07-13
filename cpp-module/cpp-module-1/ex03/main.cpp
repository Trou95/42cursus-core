#include "HumanA.h"
#include "HumanB.h"

int main()
{
	Weapon weapon("pistol");

	HumanA humanA("asda", weapon);
	humanA.attack();


	HumanB humanB("adada2");
	humanB.setWeapon(weapon);
	humanB.attack();
}