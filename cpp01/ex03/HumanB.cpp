#include "HumanB.hpp"
#include <iostream>
#include <ostream>

HumanB::HumanB(std::string name, Weapon *weapon)
{
    this->weapon = weapon;
    this->name = name;
}

HumanB::HumanB(std::string name)
{
    this->weapon = NULL;
    this->name = name;
}

HumanB::~HumanB(void)
{
    //check if need to free weapon
}

void    HumanB::attack()
{
    if (this->weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}

void    HumanB::setWeapon(Weapon *newWeapon)
{
    this->weapon = newWeapon;
}

void    HumanB::setWeapon(Weapon newWeapon)
{
    this->weapon = &newWeapon;
}