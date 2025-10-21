#include "Array.hpp"

int main(){
    try {
        std::cout << "=== Test Array<int> ===" << std::endl;
    
        // Empty array
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        // Array with size
        Array<int> arr2(5);
        for (unsigned int i = 0; i < arr2.size(); ++i)
            arr2[i] = i * 10;
        
        std::cout << "arr2 elements: ";
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
    
        // Copy constructor
        Array<int> arr3(arr2);
        std::cout << "arr3 elements (copy of arr2): ";
        for (unsigned int i = 0; i < arr3.size(); ++i)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;
    
        // Modify copy to check deep copy
        arr3[0] = 999;
        std::cout << "arr2[0] after modifying arr3: " << arr2[0] << std::endl; // should still be 0
    
        // Assignment operator
        Array<int> arr4;
        arr4 = arr2;
        std::cout << "arr4 elements (assigned from arr2): ";
        for (unsigned int i = 0; i < arr4.size(); ++i)
            std::cout << arr4[i] << " ";
        std::cout << std::endl;
    
        // Out-of-range access
        std::cout << "Accessing arr2[10]: ";
        std::cout << arr2[10] << std::endl;
    
    } 
    catch (std::exception &e) {
        std::cout << "Caught exception: out of range" << std::endl;
    }
    
    std::cout << "\n=== Test Array<std::string> ===" << std::endl;
    
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "2025";
    
    for (unsigned int i = 0; i < strArr.size(); ++i)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;
    
    return (0);
}
