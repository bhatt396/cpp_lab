#include <iostream>

  // Function template for finding the maximum of two values
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Function template overloading for finding the maximum of three values
template<typename T>
T maximum(T a, T b, T c) {
    return maximum(maximum(a, b), c); // Utilizing the previously defined maximum function for two values
}

int main() {
    std::cout << "Maximum of 10 and 20: " << maximum(10, 20) << std::endl;
    std::cout << "Maximum of 15.6 and 12.9: " << maximum(15.6, 12.9) << std::endl;
    std::cout << "Maximum of 5, 7, and 3: " << maximum(5, 7, 3) << std::endl;

    return 0;
}
