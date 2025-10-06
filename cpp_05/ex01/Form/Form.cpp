#include "Form.hpp"

Form::Form() : _name("Undefined"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		_isSigned = other._isSigned;
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
	return (_isSigned);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
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

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form '" << form.getName() << "', signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExecute() << ".";
	return os;
}
