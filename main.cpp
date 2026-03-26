#include "Student.h"
#include <vector>
#include <limits>

int main() {
    vector<Student> students;
    int choice;

    loadFromFile(students);

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            addCourseGrade(students);
            break;
        case 4:
            saveToFile(students);
            cout << "Exiting... Data saved successfully.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
