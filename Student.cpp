//
// Created by herve on 5/1/26.
//

#include "Student.h"

Student::Student(const int id, const std::string &name, const std::string &gender, const std::string &email, const std::string &niveau) {
    this->name = name;
    this->gender = gender;
    this->email = email;
    this->niveau = niveau;
    this->id = id;
}
Student* Student::createStudent(const int id, const std::string& name,const std::string& gender,const std::string& email,const std::string& niveau){
    return new Student(id,name,gender,email,niveau);
};
Student Student::displayStudent() {
    return *this;
}

std::string Student::deleteStudent() const {
    return "Student with id " + std::to_string(this->id) + " has been deleted.";
}
Student Student::updateStudent() {
    return *this;
}
