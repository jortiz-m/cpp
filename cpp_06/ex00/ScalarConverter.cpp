#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	if (this!= &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool	is_char(const std::string &str)
{
	if (str.length() == 3 && (str[0] == '\'' && str[2] == '\''))
		return true;
	return false;
}

bool	is_int(const std::string &str)
{
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for(; i < str.length(); i++) {
		if(str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool is_floating(const std::string &str, bool require_f)
{
    if (require_f)
    {
        if (str == "nanf" || str == "+inff" || str == "-inff")
            return true;
    }
    else
    {
        if (str == "nan" || str == "+inf" || str == "-inf")
            return true;
    }
    std::string core = str;
    if (require_f)
    {
        if (str[str.length() - 1] != 'f')
            return false;
        core = str.substr(0, str.length() - 1);
    }
    size_t i = 0;
    if (core[i] == '+' || core[i] == '-')
        i++;
    bool has_point = false;
    bool has_digit = false;

    for (; i < core.length(); i++)
    {
        if (core[i] == '.')
        {
            if (has_point)
                return false;
            has_point = true;
        }
        else if (core[i] >= '0' && core[i] <= '9')
            has_digit = true;
        else
            return false;
    }
    return (has_point && has_digit);
}

bool is_float(const std::string &str)
{
    return is_floating(str, true);
}

bool is_double(const std::string &str)
{
    return is_floating(str, false);
}

void ScalarConverter::convert(const std::string &str)
{
    if (is_char(str))
    {
        char c = str[1];
        int n = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (is_int(str))
    {
        int n = std::atoi(str.c_str());
        float f = static_cast<float>(n);
        double d = static_cast<double>(n);

        std::cout << "char: ";
        if (n >= 0 && n <= 127 && isprint(n)) std::cout << static_cast<char>(n);
        else std::cout << "Non displayable";
        std::cout << std::endl;

        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (is_float(str))
    {
        float f = static_cast<float>(std::atof(str.c_str()));
        double d = static_cast<double>(f);

        std::cout << "char: ";
        if (f >= 0 && f <= 127 && isprint(static_cast<int>(f))) std::cout << static_cast<char>(f);
        else std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "int: ";
        if (f >= -2147483648.f && f <= 2147483647.f) std::cout << static_cast<int>(f);
        else std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (is_double(str))
    {
        double d = std::atof(str.c_str());
        float f = static_cast<float>(d);

        std::cout << "char: ";
        if (d >= 0 && d <= 127 && isprint(static_cast<int>(d))) std::cout << static_cast<char>(d);
        else std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "int: ";
        if (d >= -2147483648. && d <= 2147483647.) std::cout << static_cast<int>(d);
        else std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
