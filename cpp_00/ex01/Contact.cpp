#include "Contact.hpp"
#include <iostream>

static std::string getNonEmptyInput(const std::string &prompt) 
{
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);

    while (input.empty()) 
    {
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    return (input);
}

void Contact::fill() 
{
    first_name = getNonEmptyInput("First Name: ");
    last_name = getNonEmptyInput("Last Name: ");
    nickname = getNonEmptyInput("Nickname: ");
    phone_number = getNonEmptyInput("Phone Number: ");
    darkest_secret = getNonEmptyInput("Darkest Secret: ");
}

void Contact::displayFull() const 
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void Contact::displaySummary(int index) const
{
    std::cout << "|";
    std::cout.width(10);
    std::cout << index << "|";

    std::string items[3] = {first_name, last_name, nickname};
    int i = 0;
    while (i < 3) 
    {
        std::cout.width(10);
        if (items[i].length() > 10)
            std::cout << items[i].substr(0, 9) + ".";
        else
            std::cout << items[i];
        std::cout << "|";
        i++;
    }
    std::cout << std::endl;
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
