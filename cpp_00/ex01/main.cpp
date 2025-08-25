#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() 
{
    PhoneBook phonebook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command); // leer el comando que el usuario ingresa

        if (command == "ADD") 
        {
            phonebook.add_contact();
        } 
        else if (command == "SEARCH") 
        {
            phonebook.search_contact();
        } 
        else if (command == "EXIT") 
        {
            break ;
        } 
        else 
        {
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT" << std::endl;
        }
    }
    return (0);
}
