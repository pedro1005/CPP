#include "Zombie.hpp"
#include <iostream>
#include <ostream>

Zombie::Zombie(void)
{
    this->name = "";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " was destroyed!" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
    return (new Zombie(name));
}
