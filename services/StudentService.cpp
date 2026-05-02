#include "StudentService.h"
#include <iostream>
#include <iomanip>

StudentService::StudentService() {}

StudentService::~StudentService() {
    clearAll();
}

void StudentService::addStudent(int id, const std::string& name, const std::string& gender, 
                                 const std::string& email, const std::string& niveau) {
    Student* newStudent = Student::createStudent(id, name, gender, email, niveau);
    students.push_back(newStudent);
    std::cout << "\n✓ Student added successfully!" << std::endl;
}

Student* StudentService::getStudent(int id) {
    for (auto student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

void StudentService::displayAllStudents() {
    if (students.empty()) {
        std::cout << "\n✗ No students in the system." << std::endl;
        return;
    }
    
    std::cout << "\n--- All Students ---" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::setw(20) << "Name" 
              << std::setw(10) << "Gender" << std::setw(25) << "Email" 
              << std::setw(10) << "Niveau" << std::endl;
    std::cout << std::string(70, '-') << std::endl;
    
    for (const auto& student : students) {
        std::cout << std::left << std::setw(5) << student->getId() 
                  << std::setw(20) << student->getName() 
                  << std::setw(10) << student->getGender() 
                  << std::setw(25) << student->getEmail() 
                  << std::setw(10) << student->getNiveau() << std::endl;
    }
}

void StudentService::updateStudent(int id, const std::string& name, const std::string& gender, 
                                    const std::string& email, const std::string& niveau) {
    Student* student = getStudent(id);
    if (student != nullptr) {
        student->setName(name);
        student->setGender(gender);
        student->setEmail(email);
        student->setNiveau(niveau);
        std::cout << "\n✓ Student updated successfully!" << std::endl;
    } else {
        std::cout << "\n✗ Student with ID " << id << " not found." << std::endl;
    }
}

bool StudentService::deleteStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            students.erase(it);
            std::cout << "\n✓ Student deleted successfully!" << std::endl;
            return true;
        }
    }
    std::cout << "\n✗ Student with ID " << id << " not found." << std::endl;
    return false;
}

std::vector<Student*> StudentService::getAllStudents() {
    return students;
}

int StudentService::getStudentCount() {
    return students.size();
}

void StudentService::clearAll() {
    for (auto student : students) {
        delete student;
    }
    students.clear();
}