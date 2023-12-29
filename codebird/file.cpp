#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    float marks;
    Student() {}
};

int main() {
    const int arraySize = 3;
    Student students[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        cout << "Enter student details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }

    cout << "Student details:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "Name: " << students[i].name << ", Roll Number: " << students[i].rollNumber
            << ", Marks: " << students[i].marks << endl;
    }

    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < arraySize; ++i) {
        outFile << students[i].name << " " << students[i].rollNumber << " " << students[i].marks << endl;
    }

    outFile.close();

    ifstream inFile("students.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading from file:" << endl;
    string name;
    int rollNumber;
    float marks;

    while (inFile >> name >> rollNumber >> marks) {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Marks: " << marks << endl;
    }

    inFile.close();
    system("pause");
    return 0;
}
