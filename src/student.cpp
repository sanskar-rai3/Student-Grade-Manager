#include "student.h"

// Used Headers in student.h
// #include <string>
// #include <vector>
// #include <fstream>

#include <iostream>
#include <sstream>

Student::Student(const std::string &name, float gpa) : name(name), gpa(gpa) {}

std::string Student::getName() const {
    return name;
}

float Student::getGPA() const {
    return gpa;
}

float averageGPA(const std::vector<Student> &datas) {
    if (datas.empty()) return -1;

    float sum = 0;
    for (const Student &data : datas) {
        sum += data.getGPA();
    }

    return sum / datas.size();
}

void loadData(std::vector<Student> &datas, std::ifstream &inFile) {
    datas.clear();

    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string name, strGPA;

        if (std::getline(ss, name, ',') && std::getline(ss, strGPA)) {
            datas.emplace_back(name, std::stof(strGPA));
        }
    }
}

void storeData(const std::vector<Student> &datas, std::ofstream &outFile) {
    outFile << "Name,GPA" << '\n';
    
    for (const Student &data : datas) {
        outFile << data.getName() << ',' << data.getGPA() << '\n';
    }
}

void listAllStudent(const std::vector<Student> &datas) {
    if (datas.empty()) return;
    std::cout << "Name,GPA" << '\n';

    for (const Student &data : datas) {
        std::cout << data.getName() << ',' << data.getGPA() << '\n';
    }
}

void addStudent(std::vector<Student> &datas, std::string name, float gpa) {

}

void removeStudent(std::vector<Student> &datas, std::string name) {

}