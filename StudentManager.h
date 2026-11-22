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
    bool deleted = false;
};

class StudentManager
{
private:
    std::vector<Student> students;

    //std::optional<Student> findStudent(int id);
public:
    std::optional<Student> findStudent(int id);
    StudentManager();
    void showStudents();
    void addStudent();
    void searchStudent();
    void checkResult();
    void sortBymarks();
    void updateStudent();
    void deleteStudent();
    const std::vector<Student>& getStudents() const;
    void addStudent(const Student& s);
    void deleteStudent(int id);
    void saveToFile() const;
    void loadFromFile();
};