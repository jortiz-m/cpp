#include "PmergeMe/PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe sorter;
        
        sorter.parseInput(argc, argv);
        sorter.displayBefore();
        sorter.sortVector();
        sorter.sortDeque();
        sorter.displayAfter();
        sorter.displayTimes();
        
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}