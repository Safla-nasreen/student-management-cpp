#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    double marks;
};

int main() {
    std::vector<Student> students;
    students.push_back({1, "Ram", 64.5});
    students.push_back({2, "Anu", 72.0});
    students.push_back({3, "Ravi", 85.5});
    
    std::cout<<"Student details :"<<std::endl;
    for(const Student& s : students){
        std::cout<<s.id<<"--"<<s.name<<"--"<<s.marks<<std::endl;
    }
    return 0;
}