#ifndef FORM_HPP
#define FORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_beSign;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};

		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		const std::string& 	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;

		void				beSigned(const Bureaucrat& Bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
