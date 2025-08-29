#include "Zombie.hpp"

int	main() 
{
	Zombie zombie("Jon");
	zombie.announce();

	randomChump("Jonhy");

	Zombie* anotherZombie = newZombie("Jonathan");
	anotherZombie->announce();
	delete (anotherZombie);

	return (0);
}

// dos tipos de crear objetos, stack y heap(*), stack es un espacio de memoria que se utiliza para almacenar datos de forma temporal
// mientras que heap es un espacio de memoria que se utiliza para almacenar datos dinámicamente y hay que liberar manualmente
// un * creas un espacio de memoria, es como si se asignara un malloc automático
