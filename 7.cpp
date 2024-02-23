//WAP to scan details of 48 students and write it to a file student.txt. 
//Also scan the details of students from the file and display to the console

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    string department;
};

// Function to scan details of students and write them to a file
void writeStudentDetailsToFile() {
    ofstream outFile("student.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    Student student;
    for (int i = 0; i < 48; ++i) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, student.name);
        cout << "Age: ";
        cin >> student.age;
        cin.ignore(); // Clear input buffer
        cout << "Department: ";
        getline(cin, student.department);

        outFile << student.name << "," << student.age << "," << student.department << endl;
    }

    outFile.close();
    cout << "Student details written to file successfully." << endl;
}

// Function to read details of students from the file and display them to the console
void readStudentDetailsFromFile() {
    ifstream inFile("student.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    Student student;
    int count = 0;
    while (getline(inFile, student.name, ',') &&
           inFile >> student.age &&
           getline(inFile >> ws, student.department)) {
        ++count;
        cout << "Details of student " << count << ":" << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Department: " << student.department << endl;
        cout << endl;
    }

    inFile.close();
}

int main() {
    writeStudentDetailsToFile();
    cout << "\nReading student details from file:\n" << endl;
    readStudentDetailsFromFile();
    return 0;
}
