#include "Harl.h"

Harl::Harl()
{
	void (Harl::*tmp[4])(void) { &Harl::debug,&Harl::info, &Harl::warning, &Harl::error};
	const char* str[4] = { "DEBUG","INFO","WARNING","ERROR" };
	for (int i = 0; i < 4; i++){
		_levels[i] = str[i];
		fn[i] = tmp[i];
	}
}

void Harl::debug() {
	std::cout << "{DEBUG]" << std::endl;
}

void Harl::info() {
	std::cout << "[INFO]" << std::endl;
}

void Harl::warning(){
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR]" << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		while (_levels[i] == level) {
			while(i < 4)
				(this->*fn[i++])();
			return;
		}
	}
}