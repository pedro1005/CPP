#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class   ClapTrap
{
    protected:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDamage;
    
    public:

        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator = (const ClapTrap &copy);
        virtual ~ClapTrap();
        
        virtual void    attack(const std::string &target);  // cost 1 energyPoint; target.hp -= amount
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);    // cost 1 energyPoint;

        int     getHitPoints() const;
        int     getEnergyPoints() const;
        int     getAttackDamage() const;
        std::string getName() const;
        void    setHitPoints(int hp);
        void    setEnergyPoints(int ep);
        void    setAttackDamage(int ad);
        void    setName(const std::string &name);
    // ClapTrap can’t do anything if it has no hit points or energy points left.
};

#endif