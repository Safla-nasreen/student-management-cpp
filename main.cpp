#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    double marks;
};
void showStudents(const std::vector<Student> &students){
    for(const Student& s : students){
        std::cout<<s.id<<"--"<<s.name<<"--"<<s.marks<<std::endl;
    }
}
int main() {
    std::vector<Student> students;
    students.push_back({1, "Ram", 64.5});
    students.push_back({2, "Anu", 72.0});
    students.push_back({3, "Ravi", 85.5});
    int choice;
    do{
        std::cout<<"\n1. Show students\n0. Exit\nEnter choice: ";
        std::cin>>choice;
        if(choice == 1){
             std::cout<<"Student details :"<<std::endl;
             showStudents(students);
        }
    }while(choice != 0);
    
    return 0;
}