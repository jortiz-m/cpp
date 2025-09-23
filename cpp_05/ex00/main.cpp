#include "Bureaucrat.hpp"

int main()
{
    try 
	{
        Bureaucrat b("Juan");
        b.decrementGrade();
    } 
	catch (const std::exception& e)
	{
        std::cout << e.what() << std::endl;
    } 
    return (0);
}
