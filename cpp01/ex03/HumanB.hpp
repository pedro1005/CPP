#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;    
public:
    HumanB(std::string name, Weapon *weapon);
    HumanB(std::string name);
    ~HumanB(void);

    void    attack(void);
    void    setWeapon(Weapon *newWeapon);
    void    setWeapon(Weapon newWeapon);
};

#endif