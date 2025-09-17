#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostrem>

class bureaucrat
{
	private:
		const std::string		name;
		unsigned int			grade;

	public:
		bureaucrat();
		bureaucrat(const  std::string &name);
		bureaucrat(const bureaucrat& other);
		bureaucrat &operator=(const bureaucrat& other);
		~bureaucrat();

		const std:string 	&getName()const;
		unsigned int		getGrade()const;
		void				incrementGrade();
		void				decrementGrade();
}

#endif