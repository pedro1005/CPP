#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
    : ClapTrap("Default") // Call the base class constructor
{
    setHitPoints(100);      // Use setter to initialize hit points
    setEnergyPoints(100);    // Use setter to initialize energy points
    setAttackDamage(30);    // Use setter to initialize attack damage

    std::cout << "Default FragTrap is created with "
              << getHitPoints() << " hit points, " << getEnergyPoints() 
              << " energy points, and " << getAttackDamage() 
              << " attack damage." << std::endl;
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name) // Call the base class constructor
{
    setHitPoints(100);      // Use setter to initialize hit points
    setEnergyPoints(100);    // Use setter to initialize energy points
    setAttackDamage(30);    // Use setter to initialize attack damage

    std::cout << "FragTrap " << getName() << " is created with "
              << getHitPoints() << " hit points, " << getEnergyPoints() 
              << " energy points, and " << getAttackDamage() 
              << " attack damage." << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << other.getName() << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator = (const FragTrap &other) {
    std::cout << "FragTrap copy assignment called for " << other.getName() << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " requests high fives ✋!" << std::endl;
}