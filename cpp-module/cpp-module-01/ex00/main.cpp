#include "Zombie.h"

int main()
{
    Zombie zombie;
    Zombie* zombiePtr;

    zombiePtr = newZombie("Zombie");
    zombie.announce();
    zombiePtr->announce();

    randomChump("Zombie2");

    delete zombiePtr;
}