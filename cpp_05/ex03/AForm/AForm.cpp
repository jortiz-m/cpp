#include "AForm.hpp"

AForm::AForm() : _name("Undefined"), _beSign(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
		_name(name), _beSign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		_beSign = other._beSign;
	return (*this);
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _beSign(other._beSign),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("Exception: Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("Exception: Grade is too low!");
}

const char* AForm::NoSigned::what() const throw()
{
	return ("Exception: form no signed");
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
	return (_beSign);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	int		gradeBureaucrat;

	gradeBureaucrat = bureaucrat.getGrade(); 
	if (_gradeToSign < 1)
		throw GradeTooLowException();
	else if (_gradeToSign > 150)
		throw GradeTooHighException();
	if (!isSigned())
	{
		if (gradeBureaucrat <= _gradeToSign)
		{
			_beSign = true;
			std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
		}
		else
			std::cout << bureaucrat.getName() << " couldn’t sign " << _name <<  " because grade is not enough." << std::endl; 

	}
	else
		std::cout << "It's already signed." << std::endl;
}
