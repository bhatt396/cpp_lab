#include <iostream>

template<typename T>
class Rectangle {
private:
    T length;
    T width;
public:
    Rectangle(T l, T w) : length(l), width(w) {}
    
    T calculatePerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle<int> intRectangle(5, 10);
    Rectangle<float> floatRectangle(2.5, 4.3);
    
    std::cout << "Perimeter of rectangle with integer sides: " << intRectangle.calculatePerimeter() << std::endl;
    std::cout << "Perimeter of rectangle with float sides: " << floatRectangle.calculatePerimeter() << std::endl;
    
    return 0;
}
