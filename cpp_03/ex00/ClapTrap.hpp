#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int         health;
        int         energyPoints;
        int         attackDamage;

    public:
        ClapTrap();                             //constructor
        ClapTrap(const std::string& name);      //constructor con nombre
        ~ClapTrap();                            // destructor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
