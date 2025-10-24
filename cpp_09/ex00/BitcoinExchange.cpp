#include "BitcoinExchange.hpp"

// Implementación vacía del constructor
BitcoinExchange::BitcoinExchange() {}

// Implementación vacía del destructor
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDataBase(const std::string& dataBase) {
    std::ifstream file(dataBase.c_str());
    if (!file.is_open()) {
        std::cerr << "Can't open data base." << std::endl;
        exit(1);
    }

	std::string line;
    while (std::getline(file, line)) {
		//separar line en fecha y valor
        _dataBase[fecha] = valor;
    }
}

void BitcoinExchange::getDataBase() {
	//con maps
	std::map<std::string, double>::iterator it = _dataBase.begin();
	for (it != _dataBase.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	// esto para formato string
    std::cout << _dataBase << std::endl;
}

/*
std::string line;
    while (std::getline(file, line)) {
        _dataBase += line + '\n';
    }
// Comprueba que la cabecera sea exactamente "Date,exchange_rate" o "Date|exchange_rate"
bool checkHeader(const std::string &line) {
	std::string h = trim(line);
	return (h == "Date,exchange_rate" || h == "Date|exchange_rate");
}

bool checkYear(int y) {
	if (y < 2009)
		return false;
}

int checkDay(int y, int m) {
	if (d < 1 || d > 31)
		return false;
	// comprobación "manual" por mes
	switch (m) {
		case 1: return 31; // enero
		case 2: return isLeapYear(y) ? 29 : 28; // febrero (excepción)
		case 3: return 31; // marzo
		case 4: return 30; // abril
		case 5: return 31; // mayo
		case 6: return 30; // junio
		case 7: return 31; // julio
		case 8: return 31; // agosto
		case 9: return 30; // septiembre
		case 10: return 31; // octubre
		case 11: return 30; // noviembre
		case 12: return 31; // diciembre
		default: return 0;
	}
}

bool checkMonth(int m) {
	if (m < 1 || m > 12)
		return false;

}

bool checkSeparator(char c) {
	if (c != ',' || c != '|')
		return false;
}
*/