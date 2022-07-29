#include "Cat.h"

Cat::Cat() {
	type = "Cat";
	cout << type << " created" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
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
	cout << type << " destroyed" << std::endl;
}