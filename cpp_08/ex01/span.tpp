#include "span.hpp"

Span::Span(unsigned int N) : _maxSize(N), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::exception();
    _numbers.push_back(number);
}

template <typename It>
void Span::addNumbers(It begin, It end) {
    for (It it = begin; it != end; ++it) {
        if (_numbers.size() >= _maxSize)
            throw std::exception();
        _numbers.push_back(*it);
    }
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::exception();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::exception();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}
