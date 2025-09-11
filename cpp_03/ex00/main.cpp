#include "ClapTrap.hpp"

int	main(void) 
{
	ClapTrap 	trap("megaTrap");
	std::string	enemy = "evilTrap";

	trap.attack(enemy);
	trap.takeDamage(20);
	trap.beRepaired(10);
}
