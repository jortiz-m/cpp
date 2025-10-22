#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    std::vector<int>::iterator it;

    try {
        it = easyfind(v, 30);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(v, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Value not found!" << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> empty;
    try{
        it = easyfind(empty, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "It´s empty" << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> repeat;
    repeat.push_back(10);
    repeat.push_back(20);
    repeat.push_back(30);
    repeat.push_back(30);
    repeat.push_back(50);
    try{
        it = easyfind(repeat, 30);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Index: " << (it - repeat.begin()) << std::endl; 
    }
    catch (const std::exception &e){
        std::cout << "Value not found!" << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> same;
    same.push_back(10);
    same.push_back(10);
    same.push_back(10);
    same.push_back(10);
    same.push_back(10);
    try{
        it = easyfind(same, 10);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Index: " << (it - same.begin()) << std::endl; 
    }
    catch (const std::exception &e){
        std::cout << "Value not found!" << std::endl;
    }
    return 0;
}
