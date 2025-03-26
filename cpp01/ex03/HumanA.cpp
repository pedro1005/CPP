#include "HumanA.hpp"
#include <iostream>
#include <ostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}