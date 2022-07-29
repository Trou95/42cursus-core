#include "Animal.h"

Animal::Animal() {
	type = "Animal";
	cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	*this = animal;
	cout << "Default animal copy constructor called" << std::endl;
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
	cout << "Default animal destructor callled" << std::endl;
}