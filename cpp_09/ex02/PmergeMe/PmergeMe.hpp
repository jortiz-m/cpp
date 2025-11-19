#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
    private:
        std::vector<int>        _vectorData;
        std::deque<int>         _dequeData;
        double                  _vectorTime;
        double                  _dequeTime;

        void                    fordJohnsonSortVector(std::vector<int>& _vectorData);
        void                    fordJohnsonSortDeque(std::deque<int>& _vectorData);
        
        std::vector<size_t>     generateJacobsthalSequence(size_t n);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        bool parseInput(int argc, char** argv);
        bool isValidNumber(const std::string& str);
        void sortVector();
        void sortDeque();
        void displayBefore() const;
        void displayAfter() const;
        void displayTimes() const;
};

#endif
