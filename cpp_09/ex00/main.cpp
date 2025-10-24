#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange exchanger;
		exchanger.loadDataBase(av[1]);
		exchanger.getDataBase();
	}
	else
		std::cout << "Must be only one argumnet." << std::endl;
	return (0);
}
