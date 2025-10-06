#ifndef AFORM_HPP
#define AFORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string   _name;
	bool                _isSigned;
	const int           _gradeToSign;
	const int           _gradeToExecute;

public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);
	virtual ~AForm();

	const std::string&  getName() const;
	int                 getGradeToSign() const;
	int                 getGradeToExecute() const;
	bool                isSigned() const;

	void                beSigned(const Bureaucrat& bureaucrat);
	virtual void        execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif
