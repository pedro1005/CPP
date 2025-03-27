#include "HumanA.hpp"
#include <iostream>
#include <ostream>

HumanA::HumanA(std::string name, Weapon &typeWeapon) : weapon(typeWeapon)
{
    this->name = name;
}

HumanA::~HumanA(void) {}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}