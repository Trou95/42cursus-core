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
		for (int i = this->getIdeas()->length(); i > 0; i--)
			this->_ideas[i] = brain._ideas[i];
	}
	return *this;
}

const string* Brain::getIdeas() {
	return _ideas;
}

Brain::~Brain() {
	cout << "Brain destructor called" << std::endl;
}