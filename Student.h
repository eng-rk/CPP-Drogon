#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    vector<pair<string, int>> courses;
};

void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void addCourseGrade(vector<Student>& students);
void menu();

double calculateAverage(const Student& student);
void saveToFile(const vector<Student>& students);
void loadFromFile(vector<Student>& students);

#endif
