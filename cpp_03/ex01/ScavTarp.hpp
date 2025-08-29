#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap 
{
    public:
        ScavTrap();                             // Constructor por defecto
        ScavTrap(const std::string& name);      // Constructor con nombre
        ~ScavTrap();                            // Destructor

        void guardGate();                       // Modo guardia
        void attack(const std::string& target); // Ataque personalizado
};

#endif
