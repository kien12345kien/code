#include "genStack.h"
#include "genListStack.h"
#include <iostream>

// Main function
int main() {
    try {
        // Test Stack with std::vector
        Stack<int, 5> vectorStack; // Create a stack with capacity 5

        std::cout << "Testing Stack with std::vector:\n";

        vectorStack.push(10);
        vectorStack.push(20);
        vectorStack.push(30);

        std::cout << "Top element: " << vectorStack.topEl() << std::endl;
        
        while (!vectorStack.isEmpty()) {
            std::cout << "Popped element: " << vectorStack.pop() << std::endl;
        }

        // Test LLStack with std::list
        LLStack<int> listStack; // Create a stack using std::list

        std::cout << "Testing LLStack with std::list:\n";

        listStack.push(100);
        listStack.push(200);
        listStack.push(300);

        std::cout << "Top element: " << listStack.topEl() << std::endl;
        
        while (!listStack.isEmpty()) {
            std::cout << "Popped element: " << listStack.pop() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}