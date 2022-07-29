#include "Cat.h"
#include "Dog.h"

int main()
{
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* animal = new Animal();

	cout << "Type: " << cat->getType() << std::endl;
	cout << "Type: " << dog->getType() << std::endl;
	cout << "Type: " << animal->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
}