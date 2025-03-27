#include "Zombie.hpp"
#include <cstdlib>
#include <stdexcept>
#include <ostream>
#include <iostream>

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "ZHorde");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}