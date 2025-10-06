#include <ctime>
#include <cstdlib>
#include "../Bureaucrat/Bureaucrat.hpp"
#include "../AForm/AForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../Intern/Intern.hpp"

int main(void) 
{
	try {
		srand(std::time(0));
		Intern intern;

		AForm* presidential = intern.makeForm("presidential pardon", "norminette");
		Bureaucrat firstBureaucrat("Julia", 5);
		std::cout << std::endl;

		presidential->beSigned(firstBureaucrat);
		std::cout << std::endl;

		presidential->execute(firstBureaucrat);
		std::cout << std::endl;

		delete presidential;

	} catch (const AForm::NoSigned&e) {
		std::cout << "AForm Error: " << e.what() << std::endl;
		return 1;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
		return 1;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
