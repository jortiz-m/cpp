#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    Bureaucrat boss("Zaphod", 1);
    Bureaucrat mid("Ford", 75);
    Bureaucrat low("Marvin", 150);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n--- Execute without signing ---" << std::endl;
    try 
	{ 
		shrub.execute(boss); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ robo.execute(boss); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ pardon.execute(boss); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

    std::cout << "\n--- Sign with insufficient grade ---" << std::endl;

    try 
	{ 
		shrub.beSigned(low); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		robo.beSigned(low); 
	} 
	catch (std::exception& e) 
	{
		 std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		pardon.beSigned(low); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

    std::cout << "\n--- Sign with sufficient grade ---" << std::endl;

    try 
	{ 
		shrub.beSigned(mid); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		robo.beSigned(mid); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		pardon.beSigned(boss); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

    std::cout << "\n--- Execute with insufficient grade ---" << std::endl;

    try 
	{ 
		shrub.execute(low); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		robo.execute(low); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl;
	}
    try 
	{ 
		pardon.execute(low);
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

    std::cout << "\n--- Execute with sufficient grade ---" << std::endl;

    try 
	{ 
		shrub.execute(mid); 
	} 
	catch (std::exception& e) 
	{
		 std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		robo.execute(mid); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    try 
	{ 
		pardon.execute(boss); 
	} 
	catch (std::exception& e) 
	{ 
		std::cout << e.what() << std::endl; 
	}
    return 0;
}
