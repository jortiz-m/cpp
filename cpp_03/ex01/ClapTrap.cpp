#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned" << std::endl;
    return *this;
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
    if (hitPoints == 0)
    {
        std::cout << name << " is already destroyed and cannot take more damage." << std::endl;
        return;
    }
    if (amount >= static_cast<unsigned int>(hitPoints))
    {
        std::cout << name << " has been attacked and lost " << hitPoints << " hitPoints points and is now destroyed." << std::endl;
        hitPoints = 0;
    }
    else
    {
        hitPoints -= amount;
        std::cout << name << " has been attacked and lost " << amount << " hitPoints points." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints < 1)
    {
        std::cout << name << " does not have enough energy points to be repaired." << std::endl;
        return ;
    }
    if (hitPoints == 0)
    {
        std::cout << name << " is dead, cannot be repaired." << std::endl;
        return ;
    }
    if (hitPoints + amount <= 10)
    {
        hitPoints = hitPoints + amount;
        energyPoints--;
        std::cout << name << " restored hitPoints points." << std::endl;
    }
    else
    {
        hitPoints = 10;
        energyPoints--;
        std::cout << name << " restored hitPoints points." << std::endl;
    }
}
