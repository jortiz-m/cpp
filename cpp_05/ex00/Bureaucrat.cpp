#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.grade;
        return (*this);
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string& Bureaucrat::getName()const
{
    return (name);
}

int Bureaucrat::getGrade()const
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

void    Bureaucrat::incrementGrade(void)
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
