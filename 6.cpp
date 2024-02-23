#include <iostream>
#include <stdexcept>

int main() {
    try {
        // Code that may throw exceptions
        throw 10; // Throw an integer for demonstration
    } catch (...) {
        // Catch all exceptions
        std::cerr << "Caught an exception!" << std::endl;
    }

    return 0;
}