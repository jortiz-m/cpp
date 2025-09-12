#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") 
{
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) 
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat(void) 
{
	std::cout << "Cat destroyed!" << std::endl;
}

void	Cat::makeSound(void) const 
{
	std::cout << "Cat says: Meow! Meow!" << std::endl;
}