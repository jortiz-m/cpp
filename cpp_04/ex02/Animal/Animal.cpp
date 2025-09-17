#include "Animal.hpp"

Animal::Animal() : type("unknown") 
{
	std::cout << "Animal " << type << " created" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal of type " << type << " created" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called for type " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called for type " << type << std::endl;
	return (*this);
}

Animal::~Animal() 
{
	std::cout << "Animal destroyed! Type: " << type << std::endl;
}

void	Animal::makeSound(void) const 
{
	std::cout << "The " << type << " make Sound!" << std::endl;
}

std::string	Animal::getType() const 
{
	return (type);
}
