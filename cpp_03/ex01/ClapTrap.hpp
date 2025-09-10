#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int         health;
        int         energyPoints;
        int         attackDamage;

    public:
        ClapTrap();                             //constructor
        ClapTrap(const std::string& name);      //constructor con nombre
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();                            // destructor

        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif


// en este caso es protected porque las clases hijas (ScavTrap) 
// necesitan acceder a estos atributos