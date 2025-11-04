#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange exchanger;
		exchanger.loadDataBase("data2.csv"); //Cambiar nombre de data2
		exchanger.loadInputDataBase(av[1]);
		exchanger.processInput();
	}
	else
		std::cout << "Error: must be only one argument." << std::endl;
	return (0);
}

/*
Cosas a testear:
	si no hay valor pero fecha bien, bad input
	input vacio
	data vacia ( se contempla pero se queda pillao )
	2011-1-09 | 1 coge la fecha bien pero deberia de fallar
	2011-01-3 | 2 igual
	se sata una linea en el input y si tienes un error en esa linea no lo tiene en cuenta

*/
