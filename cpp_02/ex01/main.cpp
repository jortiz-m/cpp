#include "Fixed.hpp"

int main(void) 
{

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

// En este ejercicio amplío la clase Fixed para que pueda trabajar con enteros y flotantes.
// Aprendo a crear objetos con distintos tipos, convertir entre ellos y sobrecargar operadores.
// Así, mi clase Fixed se comporta como un tipo de dato nativo y puedo imprimirla directamente.
// Practico la forma canónica ortodoxa y el manejo seguro de conversiones y operadores en C++.