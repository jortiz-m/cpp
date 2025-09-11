#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("undefined") {}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) 
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
	std::cout << "Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) 
{
	if (this !=& other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void) 

{
	std::cout << "FragTrap " << name << " destroyed!!" << std::endl;
}

void FragTrap::highFivesGuys(void) 
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
