#ifndef STUDENT_MANAGEMENT_SYSTEM_STUDENTSERVICE_H
#define STUDENT_MANAGEMENT_SYSTEM_STUDENTSERVICE_H

#include "../Student.h"
#include <vector>
#include <string>

class StudentService {
private:
    std::vector<Student*> students;

public:
    StudentService();
    ~StudentService();
    
    // CRUD Operations
    void addStudent(int id, const std::string& name, const std::string& gender, 
                    const std::string& email, const std::string& niveau);
    
    Student* getStudent(int id);
    
    void displayAllStudents();
    
    void updateStudent(int id, const std::string& name, const std::string& gender, 
                       const std::string& email, const std::string& niveau);
    
    bool deleteStudent(int id);
    
    std::vector<Student*> getAllStudents();
    
    int getStudentCount();
    
    void clearAll();
};

#endif