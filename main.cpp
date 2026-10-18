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

    std::optional<Student> findStudent(int id)
    {
        auto matchId = [id](const Student &s)
        { return s.id == id; };
        auto it = std::find_if(students.begin(), students.end(), matchId);

        if (it == students.end())
        {
            return std::nullopt;
        }
        return *it;
    }

public:
    StudentManager(){
            students.push_back({1, "Ram", 64.5});
            students.push_back({2, "Anu", 72.0});
            students.push_back({3, "Ravi", 85.5});
    }
    void showStudents()
    {
        for (const Student &s : students)
        {
            std::cout << s.id << "--" << s.name << "--" << s.marks << std::endl;
        }
    }

    void addStudent()
    {
        Student s;
        std::cout << "Enter ID: ";
        std::cin >> s.id;
        std::cout << "Enter name: ";
        std::getline(std::cin >> std::ws, s.name);
        std::cout << "Enter marks: ";
        std::cin >> s.marks;
        students.push_back(s);
    }
    void searchStudent()
    {
        int id;
        std::cout << "Enter ID to search: ";
        std::cin >> id;
        auto result = findStudent(id);

        if (result)
        {
            std::cout << result->id << "--" << result->name << "--" << result->marks << std::endl;
        }
        else
        {
            std::cout << "Student not found\n";
        }
    }
    void checkResult()
    {
        int id;
        std::cout << "Enter ID to check: ";
        std::cin >> id;

        auto result = findStudent(id);

        if (!result)
        {
            std::cout << "Student not found\n";
        }
        else if (result->marks >= 40)
        {
            std::cout << result->name << " passed\n";
        }
        else
        {
            std::cout << result->name << " failed\n";
        }
    }
    void sortBymarks()
    {
        auto higherMarks = [](const Student &a, const Student &b)
        {
            return a.marks > b.marks;
        };
        std::sort(students.begin(), students.end(), higherMarks);
        std::cout << "Sorted by marks" << std::endl;
    }
    void updateStudent()
    {
        int id;
        std::cout << "Enter ID to update: ";
        std::cin >> id;

        for (Student &s : students)
        {
            if (s.id == id)
            {
                std::cout << "Enter new mark: ";
                std::cin >> s.marks;
                std::cout << s.id << "--" << s.name << "--" << s.marks << std::endl;
                return;
            }
        }
        std::cout << "Student not found" << std::endl;
    }
    void deleteStudent()
    {
        int id;
        std::cout << "Enter ID to delete: ";
        std::cin >> id;

        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].id == id)
            {
                students.erase(students.begin() + i);
                std::cout << "Student deleted" << std::endl;
                return;
            }
        }
        std::cout << "Student not found" << std::endl;
    }
};

int main()
{
    StudentManager manager;

    int choice;
    do
    {
        std::cout << "\n1. Show students\n2. Add student\n3. Search student\n4. Update student's mark\n5. Delete a student\n6. Sort by marks\n7. Check the result\n0. Exit\nEnter choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            std::cout << "Student details :" << std::endl;
            manager.showStudents();
        }
        if (choice == 2)
        {
            manager.addStudent();
        }
        if (choice == 3)
        {
            manager.searchStudent();
        }
        if (choice == 4)
        {
            manager.updateStudent();
        }
        if (choice == 5)
        {
            manager.deleteStudent();
        }
        if (choice == 6)
        {
            manager.sortBymarks();
        }
        if (choice == 7)
        {
            manager.checkResult();
        }
    } while (choice != 0);

    return 0;
}