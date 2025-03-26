#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    
    Zombie* horde;
    int     i;

    horde = new Zombie[N];
    i = 0;
    while(i < N)
        horde[i++].name = name;
    return (horde);
}