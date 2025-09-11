#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- ScavTrap Creation ---" << std::endl;
    ScavTrap scav1("Scavy");
    std::cout << "\n" << std::endl;
    scav1.attack("enemy");
    scav1.guardGate();

    std::cout << "\n--- ScavTrap Copy ---" << std::endl;
    ScavTrap scav2(scav1);
    std::cout << "\n" << std::endl;
    scav2.attack("another enemy");
    scav2.guardGate();

    std::cout << "\n--- ScavTrap Assignment ---" << std::endl;
    ScavTrap scav3;
    scav3 = scav1;
    std::cout << "\n" << std::endl;
    scav3.attack("assigned enemy");
    scav3.guardGate();

    std::cout << "\n--- Object Destruction ---" << std::endl;
    return (0);
}