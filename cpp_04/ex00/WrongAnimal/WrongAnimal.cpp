#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("None") 
{
	std::cout << "Wrong Animal of type " << type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) 
{
	std::cout << "Wrong Animal of type " << type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other) 
{
	if (this != &other)
		type = other.type;
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "Wrong Animal of type " << type << " destroyed!" << std::endl;
}

std::string	WrongAnimal::getType(void) const 
{
	return type;
}

void	WrongAnimal::makeSound(void) const 
{
	std::cout << "Wrong Animal of type " << type << " makes a wrong sound!" << std::endl;
}