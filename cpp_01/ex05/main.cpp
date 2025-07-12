#include "Harl.hpp"
#include <iostream>

int main() {
	Harl harl;

	std::cout << "---- DEBUG ----" << std::endl;
	harl.complain("DEBUG");

	std::cout << "---- INFO ----" << std::endl;
	harl.complain("INFO");

	std::cout << "---- WARNING ----" << std::endl;
	harl.complain("WARNING");

	std::cout << "---- ERROR ----" << std::endl;
	harl.complain("ERROR");

	std::cout << "---- UNKNOWN ----" << std::endl;
	harl.complain("SOMETHING ELSE"); // No hace nada

	return (0);
}
