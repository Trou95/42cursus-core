#include "Cat.h"
#include "Dog.h"

int main()
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	cout << "Type: " << animal->getType() << std::endl;
	cout << "Type: " << cat->getType() << std::endl;
	cout << "Type: " << dog->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
}