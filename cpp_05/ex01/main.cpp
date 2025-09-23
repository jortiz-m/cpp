#include "Bureaucrat/Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat firstBureaucrat("paco");
    std::cout << firstBureaucrat << std::endl;
    Form firstForm("Yearly", 28, 9);
    firstBureaucrat.signForm(firstForm);
    std::cout << std::endl;

    Bureaucrat secondBureaucrat("paco");
    std::cout << secondBureaucrat << std::endl;
    Form secondForm("Yearly", 150, 9);
    secondBureaucrat.signForm(secondForm);
    std::cout << std::endl;

    try{
        Bureaucrat thirdBureaucrat("paco");
        std::cout << thirdBureaucrat << std::endl;
        Form thirdForm("Yearly", 1500, 9);
        thirdBureaucrat.signForm(thirdForm);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try{
        Bureaucrat fourthBureaucrat("paco");
        std::cout << fourthBureaucrat << std::endl;
        Form fourthForm("Yearly", -50, 9);
        fourthBureaucrat.signForm(fourthForm);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try{
        firstBureaucrat.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
