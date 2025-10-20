#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm>

class Span {
    private:
        unsigned int            _maxSize;
        std::vector<int>        _numbers;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
    
    void    addNumber(int num);

    template <typename It>
    void    addNumbers(It begin, It end);

    int     shortestSpan() const;
    int     longestSpan() const;
};

#include "span.tpp"

#endif