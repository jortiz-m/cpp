#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) 
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const 
{
	std::cout << "Dog says: Woof! Woof!" << std::endl;
}

Dog::~Dog() 
{
	std::cout << "Dog destroyed!" << std::endl;
}
