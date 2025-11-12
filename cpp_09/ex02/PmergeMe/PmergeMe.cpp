#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), 
        _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty())
        return false;

    size_t i = 0;
    
    if (str[0] == '+')
        i++;
    
    if (str[0] == '-' || str[i] == '\0')
        return false;

    for (size_t j = i; j < str.length(); ++j) {
        if (!std::isdigit(str[j]))
            return false;
    }


    //bichear esto
    std::istringstream iss(str);
	int num;

	if (!(iss >> num))
         return false;
    return true;
}


bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Needed almost one number." << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        
        if (!isValidNumber(arg)) {
            std::cerr << "Error: Invalid number only positives numbers." << std::endl;
            return false;
        }
        
        int num = std::atoi(arg.c_str());
        
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    
    return true;
}

// Display functions
void PmergeMe::displayBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); ++i) {
        std::cout << _vectorData[i];
        if (i < _vectorData.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _vectorData.size(); ++i) {
        std::cout << _vectorData[i];
        if (i < _vectorData.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimes(double vectorTime, double dequeTime) const {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

