#include <iostream>
#include <string>

int main() 
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Memory address of string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}


// diferencia entre * y &, los punteros apuntan a direcciones de memoria, pueden ser nulos
// mientras que & no pueden ser nulas y siempre hacen referencia a un objeto existente
// igual que en C