#include "FragTrap.hpp"

int main(void) 
{
    FragTrap    frag("MC");
    std::string enemy = ("enemy");

    frag.attack(enemy);
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();

    return (0);
}
