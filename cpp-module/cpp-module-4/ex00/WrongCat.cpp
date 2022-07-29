#include "WrongCat.h"

WrongCat::WrongCat() {
	cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) {
	*this = wrongcat;
	cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat) {
	if (this != &wrongcat) {
		this->type = wrongcat.type;
	}
	return *this;
}

void WrongCat::makeSound() {
	cout << "Miyavv" << std::endl;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called" << std::endl;
}