#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Zombie {
public:
	~Zombie();
	void announce(void);
	void setName(const string name);
private:
	string _name;
};

Zombie* zombieHorde(int n, string name);



#endif