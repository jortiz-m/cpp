#include "Animal.hpp"

Animal::Animal() : type("None") 
{
    std::cout << "Animal " << type << " created" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout << "Animal of type " << type << "created" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal(void) 
{
	std::cout << "Animal of type " << type << " destroyed!" << std::endl;
}

void	Animal::makeSound(void) const 
{
	std::cout << "Animal of type " << type << " makes a generic sound!" << std::endl;
}

std::string	Animal::getType(void) const 
{
	return type;
}