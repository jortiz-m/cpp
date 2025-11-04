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
	- Data vacia ( se contempla pero se queda pillao )
	- Se salta una linea en el input y si tienes un error en esa linea no lo tiene en cuenta


	input.txt
date | value

2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-11-09 | 1
2012-01-11 | 1
2009-12-04 | 0
2025-10-29 | 12
2012-01-11 | 555

	error cases:
@jortiz-m ➜ /workspaces/cpp/cpp_09/ex00 (main) $ ./btc input.txt
Error: invalid date format, must be YYYY-MM-DD
2011-01-03 => 3 = 11.7
2011-01-03 => 2 = 7.8
2011-01-03 => 1 = 3.9
2011-01-03 => 1.2 = 4.68
2011-11-09 => 1 = 3.9
2012-01-11 => 1 = 3.9
2009-12-04 => 0 = 0
2025-10-29 => 12 = 48
2012-01-11 => 555 = 2164.5


deberia saltar la linea en blanco y procesar las demas
*/
