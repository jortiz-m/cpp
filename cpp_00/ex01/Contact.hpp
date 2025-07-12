#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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
    void displayFull() const;
    void displaySummary(int index) const;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
};

#endif