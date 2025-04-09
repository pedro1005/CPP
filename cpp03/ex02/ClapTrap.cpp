#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created.\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : name(copy.name), hitPoints(copy.hitPoints),
      energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        name = copy.name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed.\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or HP to attack.\n";
        return;
    }
    energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacked " << target << " causing damage of " << attackDamage << " hit points.\n";
    std::cout << "ClapTrap " << name << " has " << energyPoints << " energy points left.\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!.\n";
    std::cout << "ClapTrap " << name << " has " << hitPoints << " points of HP left.\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or HP left to repair.\n";
        return;
    }
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!\n"
              << "HP left: " << hitPoints << ", Energy points left: " << energyPoints << std::endl;
}

int ClapTrap::getHitPoints() const
{
    return hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return energyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return attackDamage;
}

std::string ClapTrap::getName() const
{
    return name;
}

void ClapTrap::setAttackDamage(int ad)
{
    attackDamage = ad;
}

void ClapTrap::setEnergyPoints(int ep)
{
    energyPoints = ep;
}

void ClapTrap::setHitPoints(int hp)
{
    hitPoints = hp;
}

void ClapTrap::setName(const std::string &name)
{
    this->name = name;
}

