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

/* Debug helper: print the stack contents */
void	RPN::displayStack(void) const {
    std::stack<int> copy = _numsPile;
    for (size_t i = 0; !copy.empty(); ++i) {
        std::cout << "[" << i << "] " << copy.top() << std::endl;
        copy.pop();
    }
}

/* Print final result (or error if stack malformed) */
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

/********************* Evaluation **************************/

/* Return true if the token is a valid integer number (optional leading '-') */
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

/* Return true if the token is one of the supported operators */
bool RPN::isOperator(const std::string& ar) {
    return ((ar.size() == 1) &&
        (ar[0] == '+' || ar[0] == '-' || ar[0] == '*' || ar[0] == '/'));
}

/* Validate token: numbers must be <=9 absolute value, operators allowed.
   On invalid input print single Error message and exit. */
bool RPN::tokenIsValid(const std::string& ar) {
    if (isOperator(ar))
        return true;

    if (isNumeric(ar)) {
        std::istringstream iss(ar);
        long num = 0;
        iss >> num;
        if (num > 9 || num < -9) {
            std::cerr << "Error: number can´t be greater than 9 or less than -9." << std::endl;
            exit(1);
        }
        return true;
    }

    std::cerr << "Error: invalid token, must be integer or operator + - * /" << std::endl;
    exit(1);
}

/* Process the input expression (argv style string).
   The function follows the original signature but uses const correctness. */
void	RPN::evaluateExpression(char *av, RPN& polishCalc) {
    std::istringstream iss(av);
    std::string	ar;

    while (iss >> ar && tokenIsValid(ar)) {
        if (isNumeric(ar)) {
            polishCalc.pushNumber(ar);
            continue;
        }
        polishCalc.executeOperation(ar);
    }
}

/* ************************ Operations ************************** */

/* push a number (string) onto the internal stack */
void	RPN::pushNumber(const std::string& ar) {
    int n = std::atoi(ar.c_str());
    _numsPile.push(n);
}

/* Perform an arithmetic operation using the two topmost numbers */
void	RPN::executeOperation(const std::string& ar) {
    if (_numsPile.size() < 2) {
        std::cerr << "Error: not enough operands in stack" << std::endl;
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
