#include "Form.hpp"

Form::Form() : _name("Undefined"), _beSign(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
		_name(name), _beSign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		_beSign = other._beSign;
	return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() 
{
	return ("Exception: Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Exception: Grade is too low!");
}

const std::string& Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	Form::isSigned() const
{
	return (_beSign);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
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
