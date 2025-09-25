#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	    std::string 	_target;

	public:
	class noSigned : public std::exception{
			public:
				const char* what() const throw();
		};
	    PresidentialPardonForm(const std::string& target);
	    PresidentialPardonForm(const PresidentialPardonForm& other);
	    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	    virtual ~PresidentialPardonForm();

	    void 			execute(const Bureaucrat& executor) const;
};

#endif
