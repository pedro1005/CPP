#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    // Cria um objeto ClapTrap chamado "CT-01"
    ClapTrap ct("CT-01");

    // Testa o ataque em um alvo
    ct.attack("Target-01");
    
    // Testa receber dano
    ct.takeDamage(3);
    ct.takeDamage(5);

    // Testa reparar o ClapTrap
    ct.beRepaired(4);

    // Testa receber dano até que os pontos de vida se esgotem
    ct.takeDamage(15);

    ct.attack("Target-02");

    return 0;
}
