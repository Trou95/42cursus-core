#ifndef _BRAIN_H_
#define _BRAIN_H_

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Brain {
public:
	Brain();
	Brain(const Brain& brain);
	Brain& operator=(const Brain&);

	string ideas[100];

	~Brain();
};


#endif