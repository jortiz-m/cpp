#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), health(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), health(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints < 1)
    {
        std::cout << name << " does not have enough energy points to attack." << std::endl;
        return ;
    }
    else
    {
        energyPoints--;
        std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (health == 0)
    {
        std::cout << name << " is already destroyed and cannot take more damage." << std::endl;
        return;
    }
    if (amount >= static_cast<unsigned int>(health))
    {
        std::cout << name << " has been attacked and lost " << health << " health points and is now destroyed." << std::endl;
        health = 0;
    }
    else
    {
        health -= amount;
        std::cout << name << " has been attacked and lost " << amount << " health points." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints < 1)
    {
        std::cout << name << " does not have enough energy points to be repaired." << std::endl;
        return ;
    }
    if (health == 0)
    {
        std::cout << name << " is dead, cannot be repaired." << std::endl;
        return ;
    }
    if (health + amount <= 10)
    {
        health = health + amount;
        energyPoints--;
        std::cout << name << " restored health points." << std::endl;
    }
    else
    {
        health = 10;
        energyPoints--;
        std::cout << name << " restored health points." << std::endl;
    }
}
