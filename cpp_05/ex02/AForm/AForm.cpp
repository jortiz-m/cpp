#include "AForm.hpp"

AForm::AForm() : _name("Undefined"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
const char* AForm::FormNotSignedException::what() const throw() 
{
	return ("Exception: Form is not signed!");
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("Exception: Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("Exception: Grade is too low!");
}

const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	AForm::isSigned() const
{
	return (_isSigned);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
	{
		std::cout << "It's already signed." << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << _name <<  " because grade is not high enough." << std::endl;
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm '" << Aform.getName() << "', signed: " << (Aform.isSigned() ? "yes" : "no")
	   << ", grade required to sign: " << Aform.getGradeToSign()
	   << ", grade required to execute: " << Aform.getGradeToExecute() << ".";
	return os;
}
