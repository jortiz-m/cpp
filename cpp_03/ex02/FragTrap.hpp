#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap/ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);           // <--- Constructor de copia
        FragTrap& operator=(const FragTrap& other); // <--- Operador de asignación
        ~FragTrap();

        void highFivesGuys(void);
};

#endif