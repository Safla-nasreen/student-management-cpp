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
void addStudent(std::vector<Student>& students) {
    Student s;
    std::cout << "Enter ID: ";
    std::cin >> s.id;
    std::cout<<"Enter name: ";
    std::getline(std::cin>>std::ws, s.name);
    std::cout<<"Enter marks: ";
    std::cin>>s.marks;
    students.push_back(s);
}
void searchStudent(const std::vector<Student>& students) {
    int id;
    std::cout << "Enter ID to search: ";
    std::cin >> id;

    for (const Student& s : students) {
        if(s.id == id){
            std::cout<<s.id<<"--"<<s.name<<"--"<<s.marks<<std::endl;
            return ;
        }
    }
    std::cout << "Student not found" << std::endl;
}
void updateStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter ID to update: ";
    std::cin >> id;

    for (Student& s : students) {
        if(s.id == id){
            std::cout<<"Enter new mark: ";
            std::cin>>s.marks;
            std::cout<<s.id<<"--"<<s.name<<"--"<<s.marks<<std::endl;
            return ;
        }
    }
    std::cout << "Student not found" << std::endl;
}
int main() {
    std::vector<Student> students;
    students.push_back({1, "Ram", 64.5});
    students.push_back({2, "Anu", 72.0});
    students.push_back({3, "Ravi", 85.5});
    int choice;
    do{
        std::cout<<"\n1. Show students\n2. Add student\n3. Search student\n4. Update student's mark\n0. Exit\nEnter choice: ";
        std::cin>>choice;
        if(choice == 1){
             std::cout<<"Student details :"<<std::endl;
             showStudents(students);
        }
        if(choice == 2){
            addStudent(students);
        }
        if(choice == 3){
            searchStudent(students);
        }
        if(choice == 4){
            updateStudent(students);
        }
    }while(choice != 0);
    
    return 0;
}