#ifndef _CAT_H_
#define _CAT_H_

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);

	void makeSound() const;
	Brain* getBrain();

	~Cat();

private:
	Brain* brain;

};



#endif