#include "Zombie.hpp"
#include <cstdlib>
#include <stdexcept>
#include <ostream>
#include <iostream>

int main(int argc,char **argv)
{
    int     hordeN;
    Zombie* horde;

    hordeN = 0;
    if (argc <= 1)
    {
        std::cout << "No horde created, try again!" << std::endl;
        return (0);
    }
    try
    {
        hordeN = std::atoi(argv[1]);
        if (hordeN <= 0)
        {
            std::cout << "Please, enter a valid number!" << std::endl;
            return (0);
        }
        horde = Zombie::zombieHorde(hordeN, "Zombie");
        int i = 0;
        while (i < hordeN)
            horde[i++].announce();
        delete[] horde;
    }
    catch(std::invalid_argument& e)
    {
        std::cout << "Invalid argument!" << std::endl;
        return (0);
    }
    catch(std::out_of_range& e)
    {
        std::cout << "Argument out of range!" << std::endl;
    }
    return (0);
}