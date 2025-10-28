#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange exchanger;
		exchanger.loadDataBase("data2.csv"); //Cambiar nombre de data2
		exchanger.loadInputDataBase(av[1]);
		//exchanger.getDataBase();
	}
	else
		std::cout << "Error: must be only one argument." << std::endl;
	return (0);
}
