#include "Bureaucrat.cpp"

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150)
{
	std::cout << "Bureaucrat named " << name << "created" std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(150)
{
	std::cout << "Bureaucrat named" << name << "created" std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this !=& other) 
	{
		grade = other.grade;
		std::cout << "Bureaucrat assignment operator called" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) 
{
	std::cout << "Bureaucrat " << _name << " has been destroyed!" << std::endl;
}

const std::string& Bureaucrat::getName()const;
{
	return (name);
}

unsigned int Bureaucrat::getGrade()const;
{
	return (grade);
}

Bureaucrat::incrementGrade();
{

}

Bureaucrat::decrementGrade();
{
	
}