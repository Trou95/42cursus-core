#ifndef _HUMANB_H_
#define _HUMANB_H_

#include "Human.h"

class HumanB : public Human {
public:
	HumanB(const string name);
	void setWeapon(const Weapon& weapon);
};

#endif