#include "ScalarConverter.hpp"

int main(int argc, char **av) 
{
    if (argc != 2) 
	{
        std::cerr << "It's necessary " << av[0] << " and one input" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}
