#include "Weapon.hpp"

Weapon::Weapon(void)
{
    this->type = "unknown weapon";
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(const std::string &newType)
{
    this->type = newType;
}