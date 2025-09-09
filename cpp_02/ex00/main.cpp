#include "Fixed.hpp"

int main(void) 
{
    Fixed a;                                        // Crea 'a' usando el constructor por defecto (value = 0)
    Fixed b(a);                                     // Crea 'b' como copia de 'a' (constructor de copia)
    Fixed c;                                        // Crea 'c' usando el constructor por defecto
    c = b;                                          // Asigna el valor de 'b' a 'c' (operador de asignación)

    std::cout << a.getRawBits() << std::endl;       // Muestra el valor interno de 'a' (debería ser 0)
    std::cout << b.getRawBits() << std::endl;       // Muestra el valor interno de 'b' (debería ser 0)
    std::cout << c.getRawBits() << std::endl;       // Muestra el valor interno de 'c' (debería ser 0)
    return (0);
}


// En este ejercicio lo que hago es crear un dato del tipo Fixed según la estructura de la clase.
// Luego, copio ese dato de dos formas distintas:
// 1. Usando el constructor de copia, creo otro dato igual al original.
// 2. Usando el operador de asignación (=), creo un dato y después lo igualo al original.
// La gracia del operador de asignación es que comprueba si el dato que quiero igualar es el mismo,
// y si es así, se salta la copia para evitar hacerla innecesariamente.
// Así, practico cómo se crean y copian objetos en C++ de forma segura y eficiente.