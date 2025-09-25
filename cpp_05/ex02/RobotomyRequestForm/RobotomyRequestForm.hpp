#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;
	public:
		class noSigned : public std::exception{
			public:
				const char* what() const throw();
		};
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		
		virtual ~RobotomyRequestForm();

		void			execute(const Bureaucrat& executor) const;
};

#endif
