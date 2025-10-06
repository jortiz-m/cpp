#include "../Bureaucrat/Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    std::cout << "First Bureaucrat" << std::endl;
    Bureaucrat firstBureaucrat("paco", 28);
    std::cout << firstBureaucrat << std::endl;
    Form firstForm("Yearly", 28, 9);
    firstForm.beSigned(firstBureaucrat);
    std::cout << std::endl;


    std::cout << "Second Bureaucrat" << std::endl;
    Bureaucrat secondBureaucrat("paco", 150);
    std::cout << secondBureaucrat << std::endl;
    Form secondForm("Yearly", 150, 9);
    secondForm.beSigned(secondBureaucrat);
    std::cout << std::endl;


    std::cout << "Third Bureaucrat" << std::endl;
    try{
        Bureaucrat thirdBureaucrat("paco", 100);
        std::cout << thirdBureaucrat << std::endl;
        Form thirdForm("Yearly", 1500, 9);
        thirdForm.beSigned(thirdBureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Fourth Bureaucrat" << std::endl;
    try{
        Bureaucrat fourthBureaucrat("paco", 100);
        std::cout << fourthBureaucrat << std::endl;
        Form fourthForm("Yearly", -50, 9);
        fourthForm.beSigned(fourthBureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Fifth Bureaucrat" << std::endl;
    try{
        Bureaucrat fifthBureaucrat("paco", 140);
        std::cout << fifthBureaucrat << std::endl;
        Form fifthForm("Yearly", 140, 9);
        fifthForm.beSigned(fifthBureaucrat);
        fifthBureaucrat.decrementGrade();
        std::cout << fifthBureaucrat << std::endl;        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Sixth Bureaucrat" << std::endl;
    try{
        Bureaucrat sixthBureaucrat("paco", 140);
        std::cout << sixthBureaucrat << std::endl;
        Form sixthForm("Yearly", 140, 9);
        sixthForm.beSigned(sixthBureaucrat);
        sixthBureaucrat.incrementGrade();
        std::cout << sixthBureaucrat << std::endl;        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
