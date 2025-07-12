#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() 
{
    std::cout << this->name << ": is destroyed" << std::endl;
}

void Zombie::setName(std::string name) 
{
    this->name = name;
}

void Zombie::announce(void) const 
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
