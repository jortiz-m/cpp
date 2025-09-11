#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("None") 
{
	std::cout << "WrongAnimal created! Type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) 
{
	std::cout << "WrongAnimal created! Type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other) 
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return *this;
}

std::string	WrongAnimal::getType(void) const 
{
	return (type);
}

void	WrongAnimal::makeSound(void) const 
{
	std::cout << "WrongAnimal makes a wrong sound!" << std::endl;
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal destroyed! Type: " << type << std::endl;
}
