#include "StudentManager.h"

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