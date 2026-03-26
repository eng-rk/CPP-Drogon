#include "Student.h"
#include <fstream>
#include <limits>

void menu() {
    cout << "\n*** Student Course Management System ***\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Add Course and Grade for Student\n";
    cout << "4. Exit\n";
}

double calculateAverage(const Student& student) {
    if (student.courses.empty()) {
        return 0.0;
    }

    int sum = 0;
    for (const auto& course : student.courses) {
        sum += course.second;
    }

    return static_cast<double>(sum) / student.courses.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    students.push_back(s);
    saveToFile(students);
    cout << "Student added successfully.\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    for (const auto& s : students) {
        cout << "\nID: " << s.id << ", Name: " << s.name << "\nCourses:\n";
        if (s.courses.empty()) {
            cout << "  No courses added yet.\n";
        }
        else {
            for (const auto& c : s.courses) {
                cout << "  " << c.first << " : " << c.second << endl;
            }
            cout << "Average Grade: " << calculateAverage(s) << endl;
        }
    }
}

void addCourseGrade(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    int studentId;
    cout << "Enter Student ID: ";
    cin >> studentId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto& s : students) {
        if (s.id == studentId) {
            string courseName;
            int grade;

            cout << "Enter Course Name: ";
            getline(cin, courseName);
            cout << "Enter Grade: ";
            cin >> grade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            s.courses.push_back({ courseName, grade });
            saveToFile(students);
            cout << "Course and grade added successfully.\n";
            cout << "Updated Average Grade: " << calculateAverage(s) << endl;
            return;
        }
    }

    cout << "Student ID not found.\n";
}

void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");

    if (!file.is_open()) {
        cout << "Error: could not open file for saving.\n";
        return;
    }

    for (const auto& student : students) {
        file << student.id << '\n';
        file << student.name << '\n';
        file << student.courses.size() << '\n';

        for (const auto& course : student.courses) {
            file << course.first << '\n';
            file << course.second << '\n';
        }
    }

    file.close();
}

void loadFromFile(vector<Student>& students) {
    ifstream file("students.txt");

    if (!file.is_open()) {
        return;
    }

    students.clear();

    while (true) {
        Student student;
        size_t courseCount;

        if (!(file >> student.id)) {
            break;
        }
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(file, student.name);

        if (!(file >> courseCount)) {
            break;
        }
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        for (size_t i = 0; i < courseCount; ++i) {
            string courseName;
            int grade;

            getline(file, courseName);
            file >> grade;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            student.courses.push_back({ courseName, grade });
        }

        students.push_back(student);
    }

    file.close();
}
