#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("StackZombie");

    return (0);
}


// un * creas un espacio de memoria, es como si se asignara un malloc automático
// heap es un espacio de memoria que se utiliza para almacenar datos dinámicamente
// stack es un espacio de memoria que se utiliza para almacenar datos de forma temporal
// new (nombre del objeto) nueva forma de hacer malloc