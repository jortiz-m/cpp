#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    int i = 0;

    Zombie* horde = zombieHorde(N, "HordeZombie");

    while (i < N) 
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;

    return (0);
}


// en este es crear un array de zombis los cuales tengo que eliminar
// manualmente, debido a que son declarados con *