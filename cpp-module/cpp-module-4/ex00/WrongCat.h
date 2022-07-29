#ifndef _WRONGCAT_H_
#define _WRONGCAT_H_

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat& wrongCat);
	WrongCat& operator=(const WrongCat& wrongcat);

	void makeSound();

	~WrongCat();
};


#endif