#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QListWidget>
#include<QLineEdit>
#include<QPushButton>
#include "StudentManager.h"

int main(int argc, char*argv[]){
    QApplication app(argc, argv);
    StudentManager manager;
    QWidget window;
    QVBoxLayout layout(&window);
    QListWidget studentsList;
    QPushButton addButton("Add Student");
    QPushButton okButton("Ok");
    QPushButton deleteButton("Delete");
    QPushButton restoreButton("Restore");
    QLineEdit idBox, nameBox, marksBox;
    idBox.setPlaceholderText("ID"); 
    nameBox.setPlaceholderText("Name");
    marksBox.setPlaceholderText("Marks");

    layout.addWidget(&studentsList);
    layout.addWidget(&addButton);
    layout.addWidget(&idBox);
    layout.addWidget(&nameBox);
    layout.addWidget(&marksBox);
    layout.addWidget(&okButton);
    layout.addWidget(&deleteButton);
    layout.addWidget(&restoreButton);

    for(const Student &s: manager.getStudents()){
        QString Line = QString::number(s.id)+" "+QString::fromStdString(s.name)+" "+QString::number(s.marks);
        studentsList.addItem(Line);

        if(s.deleted){
            QListWidgetItem* item = studentsList.item(studentsList.count() - 1);
            QFont font = item -> font();
            font.setStrikeOut(true);
            item -> setFont(font);
        }
    }

    QObject::connect(&okButton, &QPushButton::clicked, [&](){
        if(nameBox.text().isEmpty()||idBox.text().isEmpty())
            return;
        Student s{ idBox.text().toInt(), nameBox.text().toStdString(), marksBox.text().toDouble() };
        manager.addStudent(s);
        QString Line = QString::number(s.id)+" "+QString::fromStdString(s.name)+" "+QString::number(s.marks);
        studentsList.addItem(Line);
        
        idBox.clear();
        nameBox.clear(); 
        marksBox.clear();

        idBox.hide();
        nameBox.hide();
        marksBox.hide();
        okButton.hide();
    });
    QObject::connect(&idBox, &QLineEdit::returnPressed, [&](){
    nameBox.setFocus();
    });
    QObject::connect(&nameBox, &QLineEdit::returnPressed, [&](){
    marksBox.setFocus();
    });
    QObject::connect(&marksBox, &QLineEdit::returnPressed, [&](){
    okButton.click();
    });
    
    idBox.hide();
    nameBox.hide();
    marksBox.hide();
    okButton.hide();

    QObject::connect(&addButton, &QPushButton::clicked,[&]{
        idBox.show();
        nameBox.show();
        marksBox.show();
        okButton.show();
        idBox.setFocus();
    });

    QObject::connect(&deleteButton, &QPushButton::clicked, [&]{
        int row = studentsList.currentRow();
        if(row<0)
            return;
        int id = manager.getStudents()[row].id;
        manager.deleteStudent(id);
        QListWidgetItem* item = studentsList.item(row);
        QFont font = item -> font();
        font.setStrikeOut(true);
        item -> setFont(font);
    });

    QObject::connect(&restoreButton, &QPushButton::clicked, [&]{
        int row = studentsList.currentRow();
        if(row<0)
            return;
        int id = manager.getStudents()[row].id;
        manager.restoreStudent(id);
        QListWidgetItem* item = studentsList.item(row);
        QFont font = item -> font();
        font.setStrikeOut(false);
        item -> setFont(font);
    });
  
    window.show();
    return app.exec();
}