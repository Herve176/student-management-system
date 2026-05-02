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

    // Getter methods
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getGender() const { return gender; }
    std::string getEmail() const { return email; }
    std::string getNiveau() const { return niveau; }

    // Setter methods
    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setGender(const std::string& newGender) { gender = newGender; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setNiveau(const std::string& newNiveau) { niveau = newNiveau; }


};


#endif //STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
