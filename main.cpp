#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    auto matchId = [id](const Student& s){
        return s.id == id;
    };

    auto it = std::find_if(students.begin(), students.end(), matchId);
    if(it == students.end()){
        std::cout<<"Student not found\n";
    }else {
    std::cout << it->id << "--" << it->name << "--" << it->marks << std::endl;
    }

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
void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter ID to delete: ";
    std::cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if(students[i].id == id){
            students.erase(students.begin() + i);
            std::cout<<"Student deleted"<<std::endl;
            return;
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
        std::cout<<"\n1. Show students\n2. Add student\n3. Search student\n4. Update student's mark\n5. Delete a student\n0. Exit\nEnter choice: ";
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
        if(choice == 5){
            deleteStudent(students);
        }
    }while(choice != 0);
    
    return 0;
}