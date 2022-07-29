#include "Cat.h"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this != &cat) {
		this->type = cat.type;
		this->brain = new Brain(*cat.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	cout << "Miyavv" << std::endl;
}

Brain* Cat::getBrain() {
	return brain;
}

Cat::~Cat() {
	if (brain != nullptr)
		delete brain;
	cout << "Cat destructor called" << std::endl;
}