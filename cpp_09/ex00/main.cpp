#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange exchanger;
		exchanger.loadDataBase("data.csv");
		exchanger.loadInputDataBase(av[1]);
		exchanger.processInput();
	}
	else
		std::cout << "Error: must be only one argument." << std::endl;
	return (0);
}
