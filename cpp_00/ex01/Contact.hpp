#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void fill();
        void display_full() const;
        void display_summary(int index) const;

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
};

#endif
