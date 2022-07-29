#include "Dog.h"

Dog::Dog() {
	type = "Dog";
	cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	if (this != &dog) {
		this->type = dog.type;
	}
	return *this;
}

void Dog::makeSound() const {
	cout << "Havv" << std::endl;
}

Dog::~Dog() {
	cout << "Dog destructor called" << std::endl;
}