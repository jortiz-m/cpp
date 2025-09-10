#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int                 value;                        // Guarda el valor en formato punto fijo
        static const int    fractionalNbr = 8;           // Siempre 8 bits para la parte fraccionaria
    
    public:
        Fixed();                                        // Constructor por defecto, pone value en 0
        Fixed(const Fixed &other);                      // Constructor de copia
        Fixed &operator=(const Fixed &other);           // Operador de asignación
        ~Fixed();                                       // Destructor
    
        int getRawBits(void) const;                     // Devuelve el valor interno (raw)
        void setRawBits(int const raw);                 // Cambia el valor interno (raw)
};

#endif


// getRawBits() sirve para leer el valor interno del objeto (solo ver, no cambia nada).
// setRawBits(int raw) sirve para modificar el valor interno del objeto (lo cambia por el valor que le pases).
// En resumen: get = ver el valor, set