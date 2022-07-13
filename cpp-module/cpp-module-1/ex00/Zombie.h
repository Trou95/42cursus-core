#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Zombie {
public:
	Zombie(const string name);
	~Zombie();
	void announce(void);
private:
	string _name;
};

Zombie* newZombie(string name);
void randomChump(string name);


#endif