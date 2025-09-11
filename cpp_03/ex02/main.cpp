#include "FragTrap.hpp"

int main(void)
{
    std::cout << "--- FragTrap Creation ---" << std::endl;
    FragTrap pekka("Pekka");
    FragTrap walle("WALL-E");

    std::cout << "\n--- Robot Battle ---" << std::endl;
    pekka.attack("WALL-E");
    walle.takeDamage(30);

    std::cout << "\n" << std::endl;
    walle.attack("Pekka");
    pekka.takeDamage(30);

    std::cout << "\n" << std::endl;
    pekka.beRepaired(15);
    walle.beRepaired(10);

    std::cout << "\n" << std::endl;
    pekka.highFivesGuys();
    walle.highFivesGuys();

    std::cout << "\n--- Object Destruction ---" << std::endl;
    return (0);
}
