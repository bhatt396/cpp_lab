#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }
    
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        } else {
            std::cout << "Stack underflow. Cannot pop from an empty stack." << std::endl;
        }
    }
    
    T& top() {
        if (!isEmpty()) {
            return elements.back();
        } else {
            throw std::out_of_range("Stack is empty. Cannot access top element.");
        }
    }
    
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    
    std::cout << "Top element of the integer stack: " << intStack.top() << std::endl;
    
    intStack.pop();
    std::cout << "Top element after popping: " << intStack.top() << std::endl;
    
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    
    std::cout << "Top element of the string stack: " << stringStack.top() << std::endl;
    
    stringStack.pop();
    std::cout << "Top element after popping: " << stringStack.top() << std::endl;
    
    return 0;
}
