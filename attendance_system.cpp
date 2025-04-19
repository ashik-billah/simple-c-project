#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void markAttendance() {
    string name, date;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    ofstream file("attendance.txt", ios::app);
    if (file.is_open()) {
        file << name << " " << date << "\n";
        file.close();
        cout << "Attendance marked successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void viewAttendance() {
    string line;
    ifstream file("attendance.txt");
    if (file.is_open()) {
        cout << "\nAttendance Records:\n";
        cout << "-------------------\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Attendance Management System =====\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Attendance\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                markAttendance();
                break;
            case 2:
                viewAttendance();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

