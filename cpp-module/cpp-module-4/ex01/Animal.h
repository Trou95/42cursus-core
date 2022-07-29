#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>


using std::cout;
using std::string;


class Animal {
public:
	Animal();
	Animal(const Animal&);
	Animal& operator=(const Animal&);

	virtual void makeSound() const;
	const string& getType() const;

	virtual ~Animal();


protected:
	string type;

};



#endif