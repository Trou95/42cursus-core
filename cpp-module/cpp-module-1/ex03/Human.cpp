#include "Human.h"

Human::Human(const string name) : _weapon("") {
	_name = name;
}

void Human::attack() {
	if (!_name.empty() && !_weapon.getType().empty())
		cout << _name << " attacks with their weapon " << _weapon.getType() << endl;
}