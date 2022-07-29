#include "Dog.h"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	if (this != &dog) {
		this->type = dog.type;
		this->brain = new Brain(*dog.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	cout << "Havv" << std::endl;
}

Brain* Dog::getBrain() {
	return brain;
}

Dog::~Dog() {
	if (brain != nullptr)
		delete brain;
	cout << "Dog destructor called" << std::endl;
}