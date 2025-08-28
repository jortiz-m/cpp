#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : total_contacts(0), next_index(0) {}

void PhoneBook::add_contact() 
{
    contacts[next_index].fill();
    next_index = (next_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::search_contact() const
{
    int i;
    
    i = 0;
    if (total_contacts == 0) 
    {
        std::cout << "No contacts to display." << std::endl;
        return ;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    while (i < total_contacts) 
    {
        contacts[i].display_summary(i);
        i++;
    }

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (std::cin.eof()) 
    {
        std::cout << "\nEOF detected, exiting..." << std::endl;
        exit(0);
    }

    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid input. Please enter a single digit." << std::endl;
        return;
    }

    std::istringstream iss(input);
    int index;
    if (!(iss >> index) || index < 0 || index >= total_contacts)
        std::cout << "Invalid index." << std::endl;
    else 
        contacts[index].display_full();
}
