#include "Student.h"

Student::Student(int studentId, string studentName) {
    id = studentId;
    name = studentName;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

vector<Course> Student::getCourses() const {
    return courses;
}

void Student::addCourse(const string& courseName, float grade) {
    courses.push_back(Course(courseName, grade));
}