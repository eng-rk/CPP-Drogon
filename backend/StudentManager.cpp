#include "StudentManager.h"

void StudentManager::addStudent(const string& name) {
    students.push_back(Student(nextId, name));
    nextId++;
}

vector<Student>& StudentManager::getStudents() {
    return students;
}

Student* StudentManager::findStudentById(int id) {
    for (auto& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

bool StudentManager::addCourseToStudent(int studentId, const string& courseName, float grade) {
    Student* student = findStudentById(studentId);
    if (student == nullptr) {
        return false;
    }

    student->addCourse(courseName, grade);
    return true;
}