#ifndef RPN_HPP 
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <cctype>

class RPN {
    private:
        std::stack<int> _numsPile;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void	displayResult() const;

        bool    isNumeric(const std::string& ar);
        bool    isOperator(const std::string& ar);
        bool	tokenIsValid(const std::string& ar);
        void	evaluateExpression(char *av, RPN& polishCalc);

        void	pushNumber(const std::string& ar);
        void	executeOperation(const std::string& ar);
    };

#endif
