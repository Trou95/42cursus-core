#ifndef _FLAGTRAP_H_
#define _FLAGTRAP_H_

#include "ClapTrap.h"

class FlagTrap : public virtual ClapTrap {
public:
	FlagTrap();
	FlagTrap(const string& name);
	FlagTrap(const FlagTrap& scravtrap);

	~FlagTrap();

	FlagTrap& operator=(const FlagTrap& scravtrap);

	virtual void highFivesGuys();


private:

};




#endif