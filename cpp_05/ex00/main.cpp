#include "Bureaucrat.hpp"

int main()
{
    // Test 1: Valid creation and incrementing grade to the highest (should throw exception on second increment)
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade(); // Should become grade 1
        std::cout << a << std::endl;
        // This should throw an exception (grade 0 is invalid)
        a.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Creation with too high grade (should throw exception)
    try {
        Bureaucrat b("Bob", 0);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Creation with too low grade (should throw exception)
    try {
        Bureaucrat c("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Decrementing grade at the lowest (should throw exception)
    try {
        Bureaucrat d("Diana", 150);
        std::cout << d << std::endl;
        d.decrementGrade(); // Should throw exception
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Copy and assignment operator
    try {
        Bureaucrat e("Eve", 42);
        Bureaucrat f = e; // Copy constructor
        std::cout << "Copy: " << f << std::endl;
        Bureaucrat g("Gina", 100);
        g = e; // Assignment operator
        std::cout << g << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
