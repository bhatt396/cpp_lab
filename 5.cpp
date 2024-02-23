//WAP to implement rethrow exception
#include <iostream>
#include <stdexcept>

using namespace std;

void foo() {
    try {
        throw runtime_error("Error occurred in foo()");
    } catch (const runtime_error& e) {
        cerr << "Caught exception in foo(): " << e.what() << endl;
        throw; // Rethrow the caught exception
    }
}

int main() {
    try {
        foo();
    } catch (const runtime_error& e) {
        cerr << "Caught exception in main(): " << e.what() << endl;
    }

    return 0;
}
