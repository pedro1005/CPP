#include "Zombie.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Zombie* heapZombie;

    heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    randomChump("StackZ");
    std::cout << "Zombies doing stuff...stack should be destroyed already" << std::endl;
    delete heapZombie;
    return(0);
}