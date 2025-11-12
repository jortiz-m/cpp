#include "PmergeMe/PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe sorter;
    
    if (!sorter.parseInput(argc, argv)) {
        return 1;
    }
    
    sorter.displayBefore();
	sorter.displayAfter();
    
    // TODO: Implementar medición de tiempo y algoritmos de ordenación
    // Por ahora solo mostramos que el parsing funciona
    
    return 0;
}