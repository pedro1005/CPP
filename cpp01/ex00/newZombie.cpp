#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    return (new Zombie(name));
}
