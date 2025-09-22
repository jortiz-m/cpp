#include "Bureaucrat.hpp"

int main()
{
    try 
	{
        Bureaucrat b("Juan");
        b.decrementGrade();
    } 
	catch (const std::exception& exception)
	{
        std::cout << exception.what() << std::endl;
    } 
    return (0);
}
