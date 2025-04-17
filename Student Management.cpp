#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int marks[3];
    int total = 0;
    float average = 0.0;
    char grade = 'F';
};

// Function to calculate grade
char calculateGrade(float avg) {
    if (avg >= 80) return 'A';
    else if (avg >= 70) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    else return 'F';
}

// Function to calculate total, average, grade
void calculateResult(Student &s) {
    s.total = 0;
    for (int i = 0; i < 3; ++i) {
        s.total += s.marks[i];
    }
    s.average = s.total / 3.0;
    s.grade = calculateGrade(s.average);
}

// Function to input student data
Student inputStudent() {
    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter marks for 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> s.marks[i];
    }

    calculateResult(s);
    return s;
}

// Function to display one student
void displayStudent(const Student& s) {
    cout << left << setw(15) << s.name
         << setw(10) << s.total
         << setw(10) << fixed << setprecision(2) << s.average
         << setw(5) << s.grade << endl;
}

// Display all students
void displayAll(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }
    cout << "\n--- Student Report ---\n";
    cout << left << setw(15) << "Name" << setw(10) << "Total" << setw(10) << "Average" << setw(5) << "Grade" << endl;
    for (const auto& s : students) {
        displayStudent(s);
    }
}

// Search student by name
void searchStudent(const vector<Student>& students, const string& name) {
    bool found = false;
    for (const auto& s : students) {
        if (s.name == name) {
            cout << "\nStudent Found:\n";
            displayStudent(s);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

// Update student by name
void updateStudent(vector<Student>& students, const string& name) {
    bool found = false;
    for (auto& s : students) {
        if (s.name == name) {
            cout << "Enter new marks for 3 subjects: ";
            for (int i = 0; i < 3; ++i) {
                cin >> s.marks[i];
            }
            calculateResult(s);
            cout << "Student record updated.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

// Delete student by name
void deleteStudent(vector<Student>& students, const string& name) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == name) {
            students.erase(it);
            cout << "Student record deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Calculate class average
float calculateClassAverage(const vector<Student>& students) {
    if (students.empty()) return 0.0;
    int total = 0;
    for (const auto& s : students)
        total += s.total;

    return static_cast<float>(total) / (students.size() * 3);
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Management App Menu ---\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Update Student Info\n";
        cout << "5. Delete Student\n";
        cout << "6. Show Class Average\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                students.push_back(inputStudent());
                break;
            case 2:
                displayAll(students);
                break;
            case 3: {
                cout << "Enter name to search: ";
                cin.ignore();
                string searchName;
                getline(cin, searchName);
                searchStudent(students, searchName);
                break;
            }
            case 4: {
                cout << "Enter name to update: ";
                cin.ignore();
                string updateName;
                getline(cin, updateName);
                updateStudent(students, updateName);
                break;
            }
            case 5: {
                cout << "Enter name to delete: ";
                cin.ignore();
                string deleteName;
                getline(cin, deleteName);
                deleteStudent(students, deleteName);
                break;
            }
            case 6:
                cout << "Class Average: " << fixed << setprecision(2) << calculateClassAverage(students) << endl;
                break;
            case 0:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
