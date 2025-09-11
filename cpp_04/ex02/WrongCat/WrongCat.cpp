#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "WrongCat created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const 
{
    std::cout << "Wrong Animal of type " << type << " says: Muuu!" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destroyed!" << std::endl;
}
