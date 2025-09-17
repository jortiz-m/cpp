#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongCat/WrongCat.hpp"

int	main() 
{
	int	num = 6;
	Animal* animalArray[num];

	for (int i = 0; i < num; i++) 
	{
		if (i < num / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}
	for (int i = 0; i < num; i++) 
		std::cout << "Animal in array[" << i << "] is a " << animalArray[i]->getType() << std::endl;

	for (int i = 0; i < num; i++) 
		delete animalArray[i];
	return (0);
}
