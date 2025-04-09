#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap") {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap default constructor called." << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " is created with "
              << getHitPoints() << " hit points, "
              << getEnergyPoints() << " energy points, and "
              << getAttackDamage() << " attack damage." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called for " << copy.getName() << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy); // Let base class handle the copying
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " is destroyed." << std::endl;
}

// Overridden attack method
void ScavTrap::attack(const std::string &target) {
    if (getHitPoints() <= 0 || getEnergyPoints() <= 0) {
        std::cout << "ScavTrap " << getName()
                  << " has no energy or hit points left to attack." << std::endl;
        return;
    }

    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
              << getAttackDamage() << " points of damage! Energy points left: "
              << getEnergyPoints() << std::endl;
}

// Unique ScavTrap method
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode!" << std::endl;
}
