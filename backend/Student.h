#pragma once
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    string courseName;
    float grade;

    Course(string name, float g) : courseName(name), grade(g) {}
};

class Student {
private:
    int id;
    string name;
    vector<Course> courses;

public:
    Student(int studentId, string studentName);

    int getId() const;
    string getName() const;
    vector<Course> getCourses() const;

    void addCourse(const string& courseName, float grade);
};