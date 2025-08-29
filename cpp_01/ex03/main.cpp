#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() 
{
    {
        Weapon club = Weapon("crude spiked club");  // crea objeto de tipo weapon
        HumanA bob("Bob", club);                    // crea objeto de tipo HumanA con referencia a club
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}


// La clave de este ejercicio es entender cómo referenciar una clase dentro de otra.
// En este caso, la clase Weapon se referencia dentro de HumanA (por referencia) y HumanB (por puntero).
// Así, si cambias el objeto Weapon, el cambio se refleja también en los objetos HumanA y HumanB que lo usan.

// otra clave es que la clase de HumanA no puede crearse sin un arma, ya que el arma es una referencia (debe inicializarse en el constructor).
// mientras que HumanB puede crearse sin un arma, y se le puede asignar una después.