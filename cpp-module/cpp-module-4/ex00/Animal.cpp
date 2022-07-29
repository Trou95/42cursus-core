#include "Animal.h"

Animal::Animal() {
	type = "Animal";
	cout << type << " created" << std::endl;
}

Animal::Animal(const Animal& animal) {
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal) {
	if (this != &animal) {
		this->type = animal.type;
	}
	return *this;
}

const string& Animal::getType() const {
	return type;
}

void Animal::makeSound() const {

}

Animal::~Animal() {
	cout << type << " destroyed" << std::endl;
}