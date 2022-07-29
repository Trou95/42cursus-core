#ifndef _SCRAVTRAP_H_
#define _SCRAVTRAP_H_

#include "ClapTrap.h"

class ScravTrap : public ClapTrap {
public:
	ScravTrap();
	ScravTrap(const string& name);
	ScravTrap(const ScravTrap& flagtrap);

	~ScravTrap();

	ScravTrap& operator=(const ScravTrap& flagtrap);

	void guardGate();


private:

};




#endif