#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        // Default constructor
        FragTrap();

        // Parameterized constructor
        FragTrap(const std::string &name);

        // Copy constructor
        FragTrap(const FragTrap &other);

        // Copy assignment operator
        FragTrap &operator=(const FragTrap &other);

        // Destructor
        ~FragTrap();

        // Unique method
        void highFivesGuys(void);
};

#endif