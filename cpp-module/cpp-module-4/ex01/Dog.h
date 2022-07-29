#ifndef _DOG_H_
#define _DOG_H_

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& cat);
	Dog& operator=(const Dog& cat);

	void makeSound() const;

	~Dog();

private:
	Brain* brain;

};



#endif