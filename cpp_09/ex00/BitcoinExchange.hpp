#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

enum Type {
	DATA,
	INPUT
};

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <ctime>
#include <cfloat>

class BitcoinExchange {
	private:
		std::map<std::string, double>		_dataBase;
		std::string							_inputDataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void			loadDataBase(const std::string& dataBase);
		bool			checkCSVdata(std::string& date, std::string& value, std::istringstream& ss);

		void			loadInputDataBase(const std::string& dataBase);
		bool 			checkInputData(std::string& date, std::string& value, std::istringstream& ss);

		void 			processInput();

		bool 			validDate(const std::string& date, Type context);
		bool 			validValue(const std::string& value, Type context);
		int 			daysInMonth(int y, int m, Type context);
		bool 			isLeapYear(int y);
};

#endif
