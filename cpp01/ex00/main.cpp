#include "Zombie.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Zombie* heapZombie;

    heapZombie = Zombie::newZombie("HeapZ"); //error
    heapZombie->announce();
    Zombie::randomChump("StackZ"); //error
    std::cout << "Zombies doing stuff...stack should be destroyed" << std::endl;
    delete heapZombie;
    return(0);
}