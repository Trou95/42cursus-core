#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "Weapon.h"

class Human {
public:
	void attack();
protected:
	string _name;
	Weapon _weapon;

	Human(const string name);
private:
};



#endif