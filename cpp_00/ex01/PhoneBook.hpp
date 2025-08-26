#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
    Contact contacts[8];
    int     total_contacts;
    int     next_index;

public:
    PhoneBook();
    void add_contact();
    void search_contact() const;
};

#endif