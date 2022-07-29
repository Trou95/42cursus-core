#include "Brain.h"

Brain::Brain() {
	cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& brain) {
	*this = brain;
	cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
	if (this != &brain) {
		for (int i = this->ideas->length(); i > 0; i--)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	cout << "Brain destructor called" << std::endl;
}