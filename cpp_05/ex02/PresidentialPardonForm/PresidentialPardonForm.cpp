#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const char* PresidentialPardonForm::noSigned::what() const throw() 
{
	return ("Exception: it's no signed.");
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
        throw noSigned();
    if (executor.getGrade() > (unsigned int)getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
