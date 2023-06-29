#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char* INDEX_FILENAME = "employee_index.dat";
const char* DATA_FILENAME = "employee_data.dat";

struct Employee {
    int id;
    char name[50];
    char designation[50];
    double salary;
};

struct IndexRecord {
    int id;
    int dataOffset;
};

void addEmployee() {
    Employee employee;
    cout << "Enter Employee ID: ";
    cin >> employee.id;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(employee.name, 50);
    cout << "Enter Designation: ";
    cin.getline(employee.designation, 50);
    cout << "Enter Salary: ";
    cin >> employee.salary;

    ofstream dataFile(DATA_FILENAME, ios::binary | ios::app);
    if (!dataFile) {
        cerr << "Error opening data file for writing." << endl;
        return;
    }

    int dataOffset = dataFile.tellp();
    dataFile.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
    dataFile.close();

    IndexRecord indexRecord;
    indexRecord.id = employee.id;
    indexRecord.dataOffset = dataOffset;

    ofstream indexFile(INDEX_FILENAME, ios::binary | ios::app);
    if (!indexFile) {
        cerr << "Error opening index file for writing." << endl;
        return;
    }

    indexFile.write(reinterpret_cast<const char*>(&indexRecord), sizeof(IndexRecord));
    indexFile.close();

    cout << "Employee added successfully." << endl;
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    fstream indexFile(INDEX_FILENAME, ios::binary | ios::in | ios::out);
    if (!indexFile) {
        cerr << "Error opening index file for reading and writing." << endl;
        return;
    }

    IndexRecord indexRecord;
    bool found = false;
    while (indexFile.read(reinterpret_cast<char*>(&indexRecord), sizeof(IndexRecord))) {
        if (indexRecord.id == id) {
            found = true;
            break;
        }
    }

    if (!found) {
        cerr << "Employee not found." << endl;
        indexFile.close();
        return;
    }

    // Mark the index record as deleted
    indexRecord.id = -1;
    indexFile.seekp(indexFile.tellg() - sizeof(IndexRecord));
    indexFile.write(reinterpret_cast<const char*>(&indexRecord), sizeof(IndexRecord));
    indexFile.close();

    cout << "Employee deleted successfully." << endl;
}

void displayEmployee() {
    int id;
    cout << "Enter Employee ID to display: ";
    cin >> id;

    ifstream indexFile(INDEX_FILENAME, ios::binary);
    if (!indexFile) {
        cerr << "Error opening index file for reading." << endl;
        return;
    }

    IndexRecord indexRecord;
    bool found = false;
    while (indexFile.read(reinterpret_cast<char*>(&indexRecord), sizeof(IndexRecord))) {
        if (indexRecord.id == id) {
            found = true;
            break;
        }
    }

    indexFile.close();

    if (!found || indexRecord.id == -1) {
        cerr << "Employee not found." << endl;
        return;
    }

    ifstream dataFile(DATA_FILENAME, ios::binary);
    if (!dataFile) {
        cerr << "Error opening data file for reading." << endl;
        return;
    }

    dataFile.seekg(indexRecord.dataOffset);
    Employee employee;
    dataFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee));
    dataFile.close();

    cout << "Employee ID: " << employee.id << endl;
    cout << "Name: " << employee.name << endl;
    cout << "Designation: " << employee.designation << endl;
    cout << "Salary: " << employee.salary << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
