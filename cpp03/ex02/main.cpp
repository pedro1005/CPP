#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap ct("CT-01");
    ScavTrap st("ST-01");

    ct.attack(st.getName());
    st.takeDamage(ct.getAttackDamage());

    st.attack(ct.getName());
    ct.takeDamage(st.getAttackDamage());

    ct.beRepaired(10); //not possible, hp <= 0

    st.guardGate();

    FragTrap ft("FT-01");
    ft.highFivesGuys();

    return 0;
}
