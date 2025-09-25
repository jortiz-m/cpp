#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string		name;
		unsigned int			grade;

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};

	public:
		Bureaucrat();
		Bureaucrat(const  std::string &name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string&	getName()const;
		unsigned int		getGrade()const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form) const;

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
