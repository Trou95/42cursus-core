#ifndef _DOG_H_
#define _DOG_H_

#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& cat);
	Dog& operator=(const Dog& cat);

	void makeSound() const;

	~Dog();

};



#endif