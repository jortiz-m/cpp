#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();                             // Constructor por defecto
        ScavTrap(const std::string& name);      // Constructor con nombre
        ~ScavTrap();                            // Destructor

        void guardGate();                       // Método nuevo en una clase hija
        void attack(const std::string& target); // Ataque personalizado
};

#endif


// La clase ScavTrap hereda de ClapTrap, por lo que tiene acceso a sus métodos
// y atributos públicos y protegidos.
// Se ha añadido un nuevo método guardGate() que es 
// específico de ScavTrap.
// El método attack() se ha sobrescrito para proporcionar un comportamiento 
// específico para ScavTrap.