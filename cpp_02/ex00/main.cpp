#include "Fixed.hpp"

int main(void)
{
    Fixed a;                  // Default constructor
    Fixed b(a);               // Copy constructor
    Fixed c;                  // Default constructor

    c = b;                    // Copy assignment operator

    std::cout << a.getRawBits() << std::endl; // getRawBits member function called + 0
    std::cout << b.getRawBits() << std::endl; // getRawBits member function called + 0
    std::cout << c.getRawBits() << std::endl; // getRawBits member function called + 0

    return 0;
}