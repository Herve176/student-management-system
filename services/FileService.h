#ifndef STUDENT_MANAGEMENT_SYSTEM_FILESERVICE_H
#define STUDENT_MANAGEMENT_SYSTEM_FILESERVICE_H

#include "../Student.h"
#include <vector>
#include <string>

class FileService {
private:
    std::string filePath;
    const char DELIMITER = '|';  // Separator for fields

public:
    FileService(const std::string& path = "students.txt");
    
    // Save all students to file
    bool saveStudents(const std::vector<Student*>& students);
    
    // Load students from file
    std::vector<Student*> loadStudents();
    
    // Check if file exists
    bool fileExists();
    
    // Clear file
    void clearFile();
};

#endif