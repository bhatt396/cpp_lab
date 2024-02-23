// WAP to find the square root of a number using the concept of exception handing
#include <iostream>
#include <cmath>

double squareRoot(double x) {
    if (x < 0) {
        throw "Cannot find square root of a negative number";
    }
    return sqrt(x);
}

int main() {
    double num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    try {
        double result = squareRoot(num);
        std::cout << "Square root of " << num << " is: " << result << std::endl;
    } catch (const char* message) {
        std::cerr << "Error: " << message << std::endl;
    }

    return 0;
}
