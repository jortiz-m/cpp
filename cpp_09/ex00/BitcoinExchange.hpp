#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <algorithm>

enum Type { 
	DATA, 
	INPUT 
};

class BitcoinExchange {
	private:
		std::map<std::string, double>	_dataBase;
		std::string						_inputDataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDataBase(const std::string& dataBase);
		bool checkCSVdata(std::string& date, std::string& value, std::istringstream& ss);

		void loadInputDataBase(const std::string& dataBase);
		bool checkInputData(std::string& date, std::string& value, std::istringstream& ss);

		void processInput();

		bool validDate(const std::string& date, Type context);
		bool validValue(const std::string& value, Type context);
};

#endif
