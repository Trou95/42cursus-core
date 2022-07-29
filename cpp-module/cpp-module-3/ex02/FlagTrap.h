#ifndef _FLAGTRAP_H_
#define _FLAGTRAP_H_

#include "ClapTrap.h"

class FlagTrap : public ClapTrap {
public:
	FlagTrap();
	FlagTrap(const string& name);
	FlagTrap(const FlagTrap& scravtrap);

	~FlagTrap();

	FlagTrap& operator=(const FlagTrap& scravtrap);

	void highFivesGuys();


private:

};




#endif