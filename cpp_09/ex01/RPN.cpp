#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& other) {
    _numsPile = other._numsPile;
}

RPN&	RPN::operator=(const RPN& other) {
    if (this != &other)
        _numsPile = other._numsPile;
    return *this;
}

RPN::~RPN(void) {}

/********************* Display **************************/

void	RPN::displayResult(void) const {
    if (_numsPile.empty()) {
        std::cerr << "Error: no result to print" << std::endl;
        exit(1);
    }
    if (_numsPile.size() > 1) {
        std::cerr << "Error: invalid expression (remaining numbers in stack)" << std::endl;
        exit(1);
    }
    std::cout << _numsPile.top() << std::endl;
}

/********************* Parse **************************/

bool RPN::isNumeric(const std::string& ar) {
    if (ar.empty())
        return false;
    if (ar == "-")
        return false;
    for (size_t i = 0; i < ar.size(); ++i) {
        if (i == 0 && ar[i] == '-')
            continue;
        if (!std::isdigit(static_cast<unsigned char>(ar[i])))
            return false;
    }
    return true;
}

bool RPN::isOperator(const std::string& ar) {
    return ((ar.size() == 1) &&
        (ar[0] == '+' || ar[0] == '-' || ar[0] == '*' || ar[0] == '/'));
}

bool RPN::tokenIsValid(const std::string& ar) {
    if (isOperator(ar))
        return true;

    if (isNumeric(ar)) {
        std::stringstream ss(ar);

        int num;

        ss >> num;
        if (ss.fail()){
            std::cerr << "Error: number out of range." << std::endl;
            exit(1);
        }

        if (num > 9 || num < INT_MIN) {
            std::cerr << "Error: number can´t be greater than 9 or less than -9." << std::endl;
            exit(1);
        }
        return true;
    }

    std::cerr << "Error: invalid token, must be integer or operator + - * /" << std::endl;
    exit(1);
}

void	RPN::evaluateExpression(char *av, RPN& polishCalculator) {
    std::istringstream iss(av);
    std::string	ar;

    while (iss >> ar && tokenIsValid(ar)) {
        if (isNumeric(ar)) {
            polishCalculator.pushNumber(ar);
            continue;
        }
        polishCalculator.executeOperation(ar);
    }
}

/* ************************ Operations ************************** */

void	RPN::pushNumber(const std::string& ar) {
    int n = std::atoi(ar.c_str());
    _numsPile.push(n);
}

void	RPN::executeOperation(const std::string& ar) {
    if (_numsPile.size() < 2) {
        std::cerr << "Error: extra operands in stack" << std::endl;
        exit(1);
    }

    long long firstNum = _numsPile.top();
    _numsPile.pop();
    long long secondNum = _numsPile.top();
    _numsPile.pop();

    long long result = 0;

    switch (ar[0]) {
        case '+': result = secondNum + firstNum; break;
        case '-': result = secondNum - firstNum; break;
        case '*': result = secondNum * firstNum; break;
        case '/':
            if (firstNum == 0) {
                std::cerr << "Error: division by zero" << std::endl;
                exit(1);
            }
            result = secondNum / firstNum;
            break;
        default:
            std::cerr << "Error: invalid operator" << std::endl;
            exit(1);
    }

    if (result < INT_MIN || result > INT_MAX) {
        std::cerr << "Error: result out of int range" << std::endl;
        exit(1);
    }

    _numsPile.push(static_cast<int>(result));
}
