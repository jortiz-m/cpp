#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150)
{
	std::cout << "Bureaucrat named " << name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(150)
{
	std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this !=& other) 
	{
		grade = other.grade;
		std::cout << "Bureaucrat assignment operator called" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) 
{
	std::cout << "Bureaucrat " << name << " has been destroyed!" << std::endl;
}

const std::string& Bureaucrat::getName()const
{
	return (name);
}

unsigned int Bureaucrat::getGrade()const
{
	return (grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Exception: Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Exception: Grade is too low!");
}

void	Bureaucrat::incrementGrade(void) 
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade(void) 
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
	os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return os;
}
