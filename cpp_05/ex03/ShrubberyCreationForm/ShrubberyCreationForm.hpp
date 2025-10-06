#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;
	public:
		class noSigned : public std::exception{
			public:
				const char* what() const throw();
		};
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& _target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void			execute(const Bureaucrat& executor) const;
};

#endif
