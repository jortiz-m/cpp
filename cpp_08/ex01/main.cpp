#include "span.hpp"

int main()
{
    try{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        Span sp = Span(5);

        std::vector<int> nums;
        nums.push_back(3);
        nums.push_back(32);
        nums.push_back(53);
        nums.push_back(16);

        sp.addNumbers(nums.begin(), nums.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        Span pan = Span(3);
        pan.addNumber(5);
        pan.addNumber(30);
        pan.addNumber(20);
        pan.addNumber(50);
        std::cout << pan.shortestSpan() << std::endl;
        std::cout << pan.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    try{
        Span an = Span(1);
        an.addNumber(2);
        std::cout << an.shortestSpan() << std::endl;
        std::cout << an.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
