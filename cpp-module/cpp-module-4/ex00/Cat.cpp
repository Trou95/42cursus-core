#include "Cat.h"

Cat::Cat() {
	type = "Cat";
	cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this != &cat) {
		this->type = cat.type;
	}
	return *this;
}

void Cat::makeSound() const {
	cout << "Miyavv" << std::endl;
}

Cat::~Cat() {
	cout << "Cat destructor called" << std::endl;
}