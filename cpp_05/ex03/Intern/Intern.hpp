#ifndef INTER_HPP
#define INTER_HPP

#include "../AForm/AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	createPresidentialPardonForm(const std::string& target);
		AForm*	createRobotomyRequestForm(const std::string& target);
		AForm*	createShrubberyCreationForm(const std::string& target);
		AForm*	makeForm(const std::string formName, const std::string formTarget);		
};

#endif
