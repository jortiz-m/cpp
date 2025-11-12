#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <climits>

class PmergeMe {
private:
    std::vector<int>        _vectorData;
    std::deque<int>         _dequeData;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Parsing and validation
    bool parseInput(int argc, char** argv);
    bool isValidNumber(const std::string& str);

    // Ford-Johnson algorithm for both containers
    void sortVector();
    void sortDeque();

    // Display functions
    void displayBefore() const;
    void displayAfter() const;
    void displayTimes(double vectorTime, double dequeTime) const;

    // Getters for testing
    const std::vector<int>& getVector() const { return _vectorData; }
    const std::deque<int>& getDeque() const { return _dequeData; }
};

#endif
