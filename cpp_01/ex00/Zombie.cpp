#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) 
{
	std::cout << name << " zombie has been created" << std::endl;
}

Zombie::~Zombie(void) 
{
	std::cout << name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void) 
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie(std::string name) 
{
	return new Zombie(name);
}

void	randomChump(std::string name) 
{
	Zombie zombie(name);
	zombie.announce();
}