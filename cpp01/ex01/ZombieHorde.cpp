#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    
    Zombie* horde = new Zombie[N];;
    int     i;

    i = 0;
    while(i < N)
        new (&horde[i++]) Zombie(name);
    return (horde);
}