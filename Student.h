//
// Created by herve on 5/1/26.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
#define STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
#include <string>


class Student {
private:
    int id;
    std::string name;
    std::string gender;
    std::string email;
    std::string niveau;
    Student(
        int id, const std::string &name , const std::string &gender , const std::string &email , const std::string &niveau
        );
public:
   static  Student* createStudent(int id, const std::string& name,const std::string& gender,const std::string& email,const std::string& niveau);
    [[nodiscard]] std::string deleteStudent() const;
    Student displayStudent();
    Student updateStudent();

};


#endif //STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
