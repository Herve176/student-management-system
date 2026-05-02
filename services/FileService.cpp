#include "FileService.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileService::FileService(const std::string& path) : filePath(path) {}

bool FileService::saveStudents(const std::vector<Student*>& students) {
    std::ofstream file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "\n✗ Error: Could not open file for writing: " << filePath << std::endl;
        return false;
    }
    
    // Write header
    file << "ID|Name|Gender|Email|Niveau\n";
    
    // Write each student
    for (const auto& student : students) {
        file << student->getId() << DELIMITER
             << student->getName() << DELIMITER
             << student->getGender() << DELIMITER
             << student->getEmail() << DELIMITER
             << student->getNiveau() << "\n";
    }
    
    file.close();
    std::cout << "\n✓ Data saved to " << filePath << std::endl;
    return true;
}

std::vector<Student*> FileService::loadStudents() {
    std::vector<Student*> students;
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        std::cout << "\n⚠ File not found: " << filePath << std::endl;
        return students;
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> fields;
        
        // Parse CSV-like format
        while (std::getline(ss, token, DELIMITER)) {
            fields.push_back(token);
        }
        
        // Ensure we have all fields
        if (fields.size() == 5) {
            int id = std::stoi(fields[0]);
            Student* student = Student::createStudent(id, fields[1], fields[2], fields[3], fields[4]);
            students.push_back(student);
        } else {
            std::cerr << "\n✗ Invalid data format in file: " << line << std::endl;
        }
    }
    
    file.close();
    std::cout << "\n✓ Loaded " << students.size() << " students from " << filePath << std::endl;
    return students;
}

bool FileService::fileExists() {
    std::ifstream file(filePath);
    return file.good();
}

void FileService::clearFile() {
    std::ofstream file(filePath, std::ios::trunc);
    file.close();
    std::cout << "\n✓ File cleared." << std::endl;
}