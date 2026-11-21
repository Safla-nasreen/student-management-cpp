#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QListWidget>
#include "StudentManager.h"

int main(int argc, char*argv[]){
    QApplication app(argc, argv);
    StudentManager manager;
    QWidget window;
    QVBoxLayout layout(&window);
    QListWidget studentsList;

    layout.addWidget(&studentsList);
    for(const Student &s: manager.getStudents()){
        QString Line = QString::number(s.id)+" "+QString::fromStdString(s.name)+" "+QString::number(s.marks);
        studentsList.addItem(Line);
    }
    window.show();
    return app.exec();
}