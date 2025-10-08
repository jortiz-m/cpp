#ifndef SCALARConverter_HPP
#define SCALARSConverter_HPP

#include "iostream"

class ScalarConverter {
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	
	static void convert(std::string &str);
};

#endif
