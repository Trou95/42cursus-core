#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Weapon {
public:
	Weapon(const string name);
	const string& getType();
	void setType(const string type);
private:
	string type;
};


#endif