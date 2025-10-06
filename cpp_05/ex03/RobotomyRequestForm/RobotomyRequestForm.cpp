#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target ("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other)
		_target = other._target;
	return *this;
}

const char* RobotomyRequestForm::noSigned::what() const throw() 
{
	return ("Exception: it's no signed.");
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
        throw NoSigned();
    if ((int)executor.getGrade() > (int)getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* Drilling noises *" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << "!" << std::endl;
}
