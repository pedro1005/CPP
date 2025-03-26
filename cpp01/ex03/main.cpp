#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    // without dynamic allocation
    /*
    Weapon club = Weapon("Bob's weapon");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("other weapon");
    bob.attack();

    Weapon club2 = Weapon("Jim's weapon");

    HumanB jim("Jim");
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("other weapon");
    jim.attack();*/

    // with dynamic allocation
    Weapon  *arm = new Weapon("knife");

    HumanA a("A", *arm);
    a.attack();
    arm->setType("pistol");
    a.attack();

    HumanB b("B");
    b.attack();
    arm->setType("fist");
    b.setWeapon(arm);
    b.attack();

    if (arm != NULL)
        delete arm;

    return (0);
}