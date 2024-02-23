#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

// Function to scan details of employees and write them to a file
void writeEmployeeDetailsToFile(int numEmployees) {
    ofstream outFile("employee.dat", ios::binary);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    Employee emp;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin >> ws, emp.name);
        cout << "Age: ";
        cin >> emp.age;
        cout << "Salary: ";
        cin >> emp.salary;

        outFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
    }

    outFile.close();
    cout << "Employee details written to file successfully." << endl;
}

// Function to read details of employees from the file and display those with salary between 25000 and 50000
void readEmployeeDetailsFromFile() {
    ifstream inFile("employee.dat", ios::binary);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    Employee emp;
    int count = 0;
    cout << "\nEmployees with salary between 25000 and 50000:\n" << endl;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (emp.salary >= 25000 && emp.salary <= 50000) {
            ++count;
            cout << "Details of employee " << count << ":" << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Age: " << emp.age << endl;
            cout << "Salary: " << emp.salary << endl;
            cout << endl;
        }
    }

    inFile.close();
}

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cin.ignore(); // Clear input buffer

    writeEmployeeDetailsToFile(numEmployees);
    readEmployeeDetailsFromFile();
    return 0;
}
