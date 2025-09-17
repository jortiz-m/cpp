#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const 
{
	std::cout << "Cat says: Meow! Meow!" << std::endl;
}

Cat::~Cat() 
{
	std::cout << "Cat destroyed!" << std::endl;
}
