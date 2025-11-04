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

/****************************** VALIDATES *******************************/

					/* --- Spaces--- */

static std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

					/* --- Date of today --- */

static std::string getTodayDate() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char actualDaty[11];
    std::snprintf(actualDaty, sizeof(actualDaty), "%04d-%02d-%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    return std::string(actualDaty);
}

static bool isDateAfter(const std::string& date, const std::string& today) {
    return date > today;
}

					/* --- Days in diferents years --- */

static bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static int daysInMonth(int y, int m) {
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

static bool correctYear(int year, const std::string& date, Type context) {
	if (year < 2009) {
        if (context == INPUT) {
            std::cerr << "Error: invalid date, can't be less than 2009." << std::endl;
            return false;
        }
        if (context == DATA) {
            std::cerr << "Error: invalid database date, can't be less than 2009." << std::endl;
            exit(1);
        }
	}
	if (isDateAfter(date, getTodayDate())) {
        if (context == INPUT) {
            std::cerr << "Error: invalid date, can't be a day in the future." << std::endl;
            return false;
        }
        if (context == DATA){
            std::cerr << "Error: invalid database date, can't be a day in the future." << std::endl;
            exit(1);
        }

	}
	return true;
}

					/* --- Months --- */

static bool correctMonth(int month, Type context) {
	if (month < 1 || month > 12) {
        if (context == INPUT) {
            std::cerr << "Error: invalid date, the month must be between 1 and 12." << std::endl;
            return false;
        }
		if (context == DATA) {
            std::cerr << "Error: invalid database date, the month must be between 1 and 12." << std::endl;
            exit(1);
        }
	}
	return true;
}

					/* --- Days --- */

static bool correctDay(int year, int month, int day, Type context) {
	int maxDay = daysInMonth(year, month);
    if (day < 1 || day > maxDay) {
        if (context == INPUT) {
            std::cerr << "Error: invalid date, the day must be between 1 and " << maxDay << "." << std::endl;
            return false;
        }
        if (context == DATA) {
            std::cerr << "Error: invalid database date, the day must be between 1 and " << maxDay << "." << std::endl;
            exit(1);
        }
    }
	return true;
}

					/* --- Validate date --- */

bool BitcoinExchange::validDate(const std::string& date, Type context) {
	int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
	if (!correctYear(year, date, context) || !correctMonth(month, context) || !correctDay(year, month, day, context)){
		return false;
    }
    return true;
}

					/* --- Validate value --- */

bool BitcoinExchange::validValue(const std::string& value, Type context) {
    if (value.find('+') != std::string::npos) {
        if (context == INPUT) {
            std::cerr << "Error: invalid value, '+' sign not allowed." << std::endl;
            return false;
        }
        if (context == DATA) {
            std::cerr << "Error: invalid database value, '+' sign not allowed." << std::endl;
            exit(1);
        }
    }
    int count = 0;
    for (size_t i = 0; i < value.size(); ++i) {
        char c = value[i];
        if (c == '.') {
            count++;
            if (count > 1) {
                if (context == INPUT) {
                    std::cerr << "Error: invalid value, only one decimal point allowed." << std::endl;
                    return false;
                }
                if (context == DATA){
                    std::cerr << "Error: invalid database value, only one decimal point allowed." << std::endl;
                    exit(1);
                }
            }
        } 
        else if (!std::isdigit(static_cast<unsigned char>(c))) {
            if (context == INPUT) {
                std::cerr << "Error: invalid value, only positive numbers required." << std::endl;
                return false;
            }
            if (context == DATA) {
                std::cerr << "Error: invalid database value, only positive numbers required." << std::endl;
                exit(1);
            }
        }
    }
    double dValue = std::atof(value.c_str());
    if (dValue < 0.0 || dValue > 1000.0) {
        if (context == INPUT) {
            std::cerr << "Error: invalid value, must be between 0 and 1000.0" << std::endl;
            return false;
        }
        if (context == DATA) {
            std::cerr << "Error: invalid database value, must be between 0 and 1000.0" << std::endl; 
            exit(1);
        }
    }
    return true;
}


/********************************  - DATA - ********************************/

					/* --- Load data --- */

void BitcoinExchange::loadDataBase(const std::string& dataBase) {

    std::ifstream file(dataBase.c_str());

    if (!file.is_open()) {
        std::cerr << "Can't open database." << std::endl;
        exit(1);
    }

	std::string line;
	if (!std::getline(file, line))
        std::cerr << "Can't read file database." << std::endl;

	while (line.empty())
		std::getline(file, line);
	
    while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, value;
		if (line.empty())
			continue ;

		if (checkCSVdata(date, value, ss)){
			double dValue = std::atof(value.c_str());
			_dataBase[date] = dValue;
			//std::cout << date << " => " << dValue << std::endl;
		}
    }
}

					/* --- Check data --- */

bool BitcoinExchange::checkCSVdata(std::string& date, std::string& value, std::istringstream& ss) {
    Type context = DATA;

	if (!(std::getline(ss, date, ',') && std::getline(ss, value)) || date.length() != 10) {
        std::cerr << "Error: invalid database format, must be < YYYY-MM-DD,value >" << std::endl;
		exit (1);
    }
	else if (!validDate(date, context))
		return false;
	else if(!validValue(value, context))
		return false;
	return true;
}

/********************************  - INPUT - ********************************/

					/* --- Load input data --- */

static bool hasTxtExtension(const std::string& filename) {
    size_t pos = filename.rfind('.');
    if (pos == std::string::npos)
        return false;
    return filename.substr(pos) == ".txt";
}

void BitcoinExchange::loadInputDataBase(const std::string& inputDataBase) {

    std::ifstream file(inputDataBase.c_str());

    if (!hasTxtExtension(inputDataBase)) {
        std::cerr << "Error: file extension must be .txt" << std::endl;
        exit(1);
    }
    if (!file.is_open()) {
        std::cerr << "Error: can't open input data base." << std::endl;
        exit(1);
    }

    // leer primera línea (si no hay ninguna, el input está vacío -> error y exit)
    std::string line;
    int lineno = 0;
    if (!std::getline(file, line)) {
        std::cerr << "Error: input is empty." << std::endl;
        exit(1);
    }
    ++lineno;

    // detectar si la primera línea es cabecera "date" / "value"
    std::string first = trim(line);
    std::string lower = first;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    bool isHeader = (lower.find("date") != std::string::npos && lower.find("value") != std::string::npos);

    // almacenar la primera línea solo si no es cabecera
    if (!isHeader && !first.empty())
        _inputDataBase += first + "\n";

    // almacenar el resto de líneas sin validar aquí
    while (std::getline(file, line)) {
        ++lineno;
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;
        _inputDataBase += line + "\n";
    }

    // si tras procesar no hay líneas (útiles), informar y salir
    if (_inputDataBase.empty()) {
        std::cerr << "Error: input is empty." << std::endl;
        exit(1);
    }
}

					/* --- Check input data --- */

bool BitcoinExchange::checkInputData(std::string& date, std::string& value, std::istringstream& ss) {
    if (!std::getline(ss, date, '|') || !std::getline(ss, value)) {
        std::cerr << "Error: invalid format, must be < YYYY-MM-DD | value >" << std::endl;
        return false;
    }
    date = trim(date);
    value = trim(value);

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: invalid date format, must be YYYY-MM-DD" << std::endl;
        return false;
    }

    Type context = INPUT;

    if (!validDate(date, context))
        return false;
    if (!validValue(value, context))
        return false;
    return true;
}

					/* --- Process input data --- */

void BitcoinExchange::processInput() {
    std::istringstream ss(_inputDataBase);
    std::string line;
    int lineno = 0;

    while (std::getline(ss, line)) {
        ++lineno;
        if (line.empty())
            continue;

        std::istringstream lineSS(line);
        std::string inputDate, inputValue;

        // validar la línea aquí: checkInputData devuelve bool y YA imprime el mensaje de error si falla
        if (!checkInputData(inputDate, inputValue, lineSS)) {
            // sólo continuar (checkInputData ya muestra el mensaje)
            continue;
        }

        double dInputValue = std::atof(inputValue.c_str());

        // Buscar la fecha exacta en _dataBase
        std::map<std::string, double>::iterator dataIt = _dataBase.find(inputDate);

        if (dataIt != _dataBase.end()) {
            std::cout << inputDate << " => " << dInputValue << " = " << dataIt->second * dInputValue << std::endl;
        } else {
            // Buscar la fecha más cercana anterior
            dataIt = _dataBase.lower_bound(inputDate);
            if (dataIt == _dataBase.begin()) {
                std::cerr << "No data available for date " << inputDate << std::endl;
            } else {
                --dataIt; // Retrocede a la fecha anterior
                std::cout << inputDate << " => " << dInputValue << " = " << dataIt->second * dInputValue << std::endl;
            }
        }
    }
}
