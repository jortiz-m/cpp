#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(0) {}  // el cero es que se inicializa a nullptr, esta clase puede crearse sin arma

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) 
{
    this->weapon = &weapon;
}

void HumanB::attack() const 
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack" << std::endl;
}
