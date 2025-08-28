#include "PhoneBook.hpp"

int main() 
{
    PhoneBook   phonebook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command); // leer el comando que el usuario ingresa

        if (std::cin.eof())
        {
		    std::cout << "\nEOF detected, exiting..." << std::endl;
		    break ;
        }
        else if (command == "ADD") 
            phonebook.add_contact();
        else if (command == "SEARCH") 
            phonebook.search_contact();
        else if (command == "EXIT") 
            break ;
        else
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT" << std::endl;
    }
    return (0);
}
