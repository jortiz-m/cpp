#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class BitcoinExchange {
	private:
		bool								_loadDataBase;
		std::map<std::string, double>		_dataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	loadDataBase(const std::string& dataBase);
		void	getDataBase();

};

#endif
