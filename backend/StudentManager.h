#pragma once
#include "Student.h"
#include <vector>

using namespace std;

class StudentManager {
private:
    vector<Student> students;
    int nextId = 1;

public:
    void addStudent(const string& name);
    vector<Student>& getStudents();
    Student* findStudentById(int id);
    bool addCourseToStudent(int studentId, const string& courseName, float grade);
};