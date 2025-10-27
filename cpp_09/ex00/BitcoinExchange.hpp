#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <ctime>

class BitcoinExchange {
	private:
		std::map<std::string, double>		_dataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void			loadDataBase(const std::string& dataBase);
		void			getDataBase();
		bool 			validDate(const std::string& date);
		bool 			validValue(const std::string& value);
		int 			daysInMonth(int y, int m);
		bool 			isLeapYear(int y);
		bool			isDateAfter(const std::string& date, const std::string& today);
		std::string 	getTodayDate();

};

#endif
