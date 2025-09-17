#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongCat/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n--- WrongAnimal Polymorphism Test ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\n--- Direct WrongCat Test ---" << std::endl;
	WrongCat directWrongCat;
	directWrongCat.makeSound();

	delete j;
	delete i;
	delete meta;
	delete wrongCat;
	delete wrongMeta;

	return (0);
}
