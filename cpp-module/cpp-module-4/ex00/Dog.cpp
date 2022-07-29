#include "Dog.h"

Dog::Dog() {
	type = "Dog";
	cout << type << " created" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
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
	cout << type << " destroyed" << std::endl;
}