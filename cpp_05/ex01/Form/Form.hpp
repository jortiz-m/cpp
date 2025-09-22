#ifndef FORM_HPP
#define FORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"

class Form
{
	private:
		const std::string 	name;
		bool				beSign;
		int const			gradeToSign;
		int const			gradeToExecute;

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
		Form(const std::string name, const gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		const std::string& 	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSign(cosnt Bureaucrat& Bureaucrat);
}

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
