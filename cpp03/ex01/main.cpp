#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap ct("CT-01"); //ClapTrap CT-01 created.
    std::cout << "ct Name: " << ct.getName() <<  ". Attack damage: " << ct.getAttackDamage() << std::endl;
    
    ct.attack("Target-01"); //ClapTrap CT-01 attacked Target-01 causing damage of 0 hit points.
    ct.takeDamage(3); // ClapTrap CT-01 takes 3 points of damage!.
    ct.beRepaired(4); // ClapTrap CT-01 repairs 4 hit points!

    ScavTrap st("ST-01"); // ScavTrap ST-01 is created with 100 hit points, 50 energy points, and 20 attack damage.

    st.attack("Target-01"); //ScavTrap ST-01 attacks Target-01, causing 20 points of damage!
    st.takeDamage(5); // ClapTrap ST-01 takes 5 points of damage!.
    st.beRepaired(3); // ClapTrap ST-01 repairs 3 hit points!
    st.guardGate(); // ScavTrap ST-01 is now in Gatekeeper mode!

    ScavTrap* st2 = new ScavTrap(st);   // ClapTrap ST-01 copied
                                        // ScavTrap copy constructor called for ST-01
    std::cout << "st2 Name: " << st2->getName() <<  ". Attack damage: " << st2->getAttackDamage() << std::endl;

    ScavTrap st3;   //ClapTrap Default_ScavTrap created.
                    //ScavTrap default constructor called.
    st3 = *st2;     //ScavTrap assignment operator called

    std::cout << "st3 Name: " << st3.getName() <<  ". Attack damage: " << st3.getAttackDamage() << std::endl;

    delete st2;

    ClapTrap* ptr = new ScavTrap("ST-02"); // dynamic polymorphism
    std::cout << "ptr Name: " << ptr->getName() <<  ". Attack damage: " << ptr->getAttackDamage() << std::endl;
    static_cast<ScavTrap*>(ptr)->guardGate(); //downcast

    delete ptr; //check virtual destructor

    return 0;
}
