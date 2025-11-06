#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    RPN calc;
    calc.evaluateExpression(argv[1], calc);
    calc.displayResult();
    return 0;
}
