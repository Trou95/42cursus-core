#include "WrongAnimal.h"  

WrongAnimal::WrongAnimal(void)
{
	type = "Animal";
	cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
	cout << "Default WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "No Sound" << std::endl;
}

const string& WrongAnimal::getType() const
{
	return type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& animal)
{
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	cout << "Default WrongAnimal destructor called" << std::endl;
}