#include "Cat.h"
#include "Dog.h"

int main()
{
	Animal* animals[10] = {
		new Cat(),
		new Cat(),
		new Cat(),
		new Cat(),
		new Cat(),
		new Dog(),
		new Dog(),
		new Dog(),
		new Dog(),
		new Dog()
	};
	cout << "------" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
}