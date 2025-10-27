#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _dataBase = other._dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _dataBase = other._dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::getTodayDate() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char actualDaty[11];
    std::sprintf(actualDaty, "%04d-%02d-%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    return std::string(actualDaty);
}

bool BitcoinExchange::isDateAfter(const std::string& date, const std::string& today) {
    return date > today;
}

bool BitcoinExchange::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int BitcoinExchange::daysInMonth(int y, int m) {
    switch (m) {
		case 1: return 31;
		case 2: return isLeapYear(y) ? 29 : 28;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
		default: return 0;
	}
}

bool BitcoinExchange::validDate(const std::string& date){
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
            return false;
	int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());
	if (y < 2009 || y > 2025 || m < 1 || m > 12 || d < 1 || d > daysInMonth(y, m))
            return false;
    return true;
}

bool BitcoinExchange::validValue(const std::string& value){
	int count = 0;
    for (size_t i = 0; i < value.size(); ++i) {
        if (value[i] == '.') {
            count++;
            if (count > 1)
                return false;
        } 
		else if (!isdigit(value[i]))
            return false;
	}
	double dValue = std::atof(value.c_str());
	if (dValue < 0.0 || dValue > 1000.0)
            return false;
        return true;
}

void BitcoinExchange::loadDataBase(const std::string& dataBase) {
    std::ifstream file(dataBase.c_str());
    if (!file.is_open()) {
        std::cerr << "Can't open data base." << std::endl;
        exit(1);
    }
	std::string line;
	if (!std::getline(file, line))
        std::cerr << "Can't read file." << std::endl;
	std::string today = getTodayDate();

    while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, value;
		bool valid = true;

		if (!(std::getline(ss, date, ',') && std::getline(ss, value))) {
            std::cerr << "Error: invalid format " << line << std::endl;
        }
		else if (!validDate(date)){
			std::cerr << "Error: invalid date, " <<date << std::endl;
			valid = false;
		}
		else if (isDateAfter(date, today)) {
            std::cerr << "Error: date in the future, " << date << std::endl;
			valid = false;
        }
		if (!validValue(value)){
			std::cerr << "Error: invalid value, " << value << std::endl;
			valid = false;
		}
		if (_dataBase.count(date) > 0) {
            std::cerr << "Error: duplicate date, " << date << std::endl;
			valid = false;
        }
		if (valid) {
            double dValue = std::atof(value.c_str());
            _dataBase[date] = dValue;
            std::cout << date << " => " << dValue << std::endl;
        }
	}
}

void BitcoinExchange::getDataBase() {
	std::map<std::string, double>::iterator it = _dataBase.begin();
	for (; it != _dataBase.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
