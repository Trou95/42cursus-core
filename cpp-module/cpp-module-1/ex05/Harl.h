#ifndef _HARL_H_
#define _HARL_H_

#include <iostream>
#include <string>


class Harl {
public:
	Harl();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void complain(std::string level);

private:
	std::string _levels[4];
	void (Harl::*fn[4])();

};


#endif