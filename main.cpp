#include <iostream>
#include "Student.h"
#include<vector>

int main() {
    std::vector<Student*> studentList;
    std::string name, gender, email, niveau;
    int id;
    std::cout<<"new student name:";
    std::cin>>name;
    std::cout<<"new student gender:";
    std::cin>>gender;
    std::cout<<"new student Email:";
    std::cin>>email;
    std::cout<<"new student niveau:";
    std::cin>>niveau;
    std::cout<<"new student id:";
    std::cin>>id;

    // Create and add student to list
    Student* newStudent = Student::createStudent(id, name, gender, email, niveau);
    studentList.push_back(newStudent);

    std::cout << "\n✓ Student added successfully!" << std::endl;
    std::cout << "ID: " << newStudent->getId() << std::endl;
    std::cout << "Name: " << newStudent->getName() << std::endl;
    std::cout << "Gender: " << newStudent->getGender() << std::endl;
    std::cout << "Email: " << newStudent->getEmail() << std::endl;
    std::cout << "Niveau: " << newStudent->getNiveau() << std::endl;
    // Clean up memory
    for (auto student : studentList) {
        delete student;
    }

    return 0;
}
