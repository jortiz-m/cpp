#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorData(), _dequeData(), _vectorTime(0.0), _dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : 
    _vectorData(other._vectorData), 
    _dequeData(other._dequeData),
    _vectorTime(other._vectorTime),
    _dequeTime(other._dequeTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

/************************************** PARSE **************************************/

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

    std::string numPart = str.substr(i);
    if (numPart[0] == '0')
        return false;
    
    if (numPart.length() > 10)
        return false;
    // stringstream    
    if (numPart.length() == 10) {
        if (numPart > "2147483647")
            throw std::out_of_range("int out of range.");
    }
    return true;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        throw std::invalid_argument("invalid numbers of arguments.");
    }
    
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        
        if (!isValidNumber(arg)) {
            throw std::invalid_argument("only positive numbers.");
        }
        
        int num = std::atoi(arg.c_str());
        
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    
    return true;
}

/************************************** DISPLAY **************************************/

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

void PmergeMe::displayTimes() const {
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(2) 
              << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(2) 
              << _dequeTime << " us" << std::endl;
}

/************************************** SORT **************************************/

void PmergeMe::sortVector() {
    if (_vectorData.size() <= 1)
        return;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSortVector(_vectorData);
    gettimeofday(&end, NULL);
    
    _vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeque() {
    if (_dequeData.size() <= 1)
        return;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSortDeque(_dequeData);
    gettimeofday(&end, NULL);
    
    _dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

/************************************** FORD-JHONSON **************************************/

/************************************** VECTOR **************************************/

void PmergeMe::fordJohnsonSortVector(std::vector<int>& container) {
    if (container.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container.back() : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    if (pairs.size() > 1) {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            largerElements.push_back(pairs[i].first);
        }
        fordJohnsonSortVector(largerElements);
    
        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    
    std::vector<int> mainChain;
    std::vector<int> pend;
    
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].second);
        for (size_t i = 0; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].first);
            if (i > 0) {
                pend.push_back(pairs[i].second);
            }
        }
    }
    
    if (!pend.empty()) {
        std::vector<size_t> jacobsthalSeq = generateJacobsthalSequence(pend.size());
        
        for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
            if (jacobsthalSeq[i] < pend.size()) {
                int element = pend[jacobsthalSeq[i]];
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
                mainChain.insert(pos, element);
            }
        }
    }

    if (hasOdd) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }
    
    container = mainChain;
}

/************************************** DEQUE **************************************/

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container) {
    if (container.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container.back() : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    if (pairs.size() > 1) {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            largerElements.push_back(pairs[i].first);
        }
        fordJohnsonSortDeque(largerElements);
        
        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    
    std::deque<int> mainChain;
    std::vector<int> pend;
    
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].second);
        for (size_t i = 0; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].first);
            if (i > 0) {
                pend.push_back(pairs[i].second);
            }
        }
    }
    
    if (!pend.empty()) {
        std::vector<size_t> jacobsthalSeq = generateJacobsthalSequence(pend.size());
        
        for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
            if (jacobsthalSeq[i] < pend.size()) {
                int element = pend[jacobsthalSeq[i]];
                std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
                mainChain.insert(pos, element);
            }
        }
    }
    
    if (hasOdd) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }
    
    container = mainChain;
}

/************************************** JACOBSTHAL **************************************/

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    std::vector<size_t> sequence;
    
    size_t j0 = 1, j1 = 1;
    jacobsthal.push_back(j1);
    
    while (j1 < n) {
        size_t next = j1 + 2 * j0;
        jacobsthal.push_back(next);
        j0 = j1;
        j1 = next;
    }
    
    std::vector<bool> used(n, false);
    
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t limit = std::min(jacobsthal[i], n);
        size_t start = jacobsthal[i - 1];
        
        for (size_t j = limit; j > start; --j) {
            if (j - 1 < n && !used[j - 1]) {
                sequence.push_back(j - 1);
                used[j - 1] = true;
            }
        }
    }
    for (size_t i = 0; i < n; ++i) {
        if (!used[i]) {
            sequence.push_back(i);
        }
    }
    
    return sequence;
}
