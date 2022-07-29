#ifndef _WRONGANIMAL_H_
#define _WRONGANIMAL_H_

#include <iostream>
#include <string>

using std::cout;
using std::string;

class WrongAnimal
{

public:

	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& animal);
	WrongAnimal& operator=(const WrongAnimal& animal);

	void makeSound(void) const;
	const string& getType(void) const;


	virtual ~WrongAnimal(void);

protected:
	std::string		type;

};

#endif