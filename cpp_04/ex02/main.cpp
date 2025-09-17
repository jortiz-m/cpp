#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongCat/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << "\n" << std::endl;
	Dog dogOriginal;
	Dog dogCopy(dogOriginal);
	dogCopy.makeSound();

	std::cout << "\n" << std::endl;
	Cat catOriginal;
	Cat catAssigned;
	catAssigned = catOriginal;
	catAssigned.makeSound();

	std::cout << "\n--- Array de Animal* (half Dog, half Cat) ---" << std::endl;
	const int size = 6;
	Animal* animals[size];
	for (int k = 0; k < size / 2; ++k)
		animals[k] = new Dog();
	for (int k = size / 2; k < size; ++k)
		animals[k] = new Cat();

	for (int k = 0; k < size; ++k)
		animals[k]->makeSound();

	for (int k = 0; k < size; ++k)
		delete animals[k];

	return (0);
}
