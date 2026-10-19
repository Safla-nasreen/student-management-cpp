#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

struct Student
{
    int id;
    std::string name;
    double marks;
};

class StudentManager
{
private:
    std::vector<Student> students;

    std::optional<Student> findStudent(int id);
public:
    StudentManager();
    void showStudents();
    void addStudent();
    void searchStudent();
    void checkResult();
    void sortBymarks();
    void updateStudent();
    void deleteStudent();
};