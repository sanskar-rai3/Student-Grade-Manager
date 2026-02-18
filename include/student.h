#pragma once

#include <string>
#include <vector>
#include <fstream>

class Student {
private:
    std::string name;
    float gpa;

public:
    Student(const std::string &name, const float gpa);

    std::string getName() const;
    float getGPA() const;
};

float averageGPA(const std::vector<Student> &datas;

void loadData(std::vector<Student> &datas, std::ifstream &inFile);
void storeData(std::vector<Student> &datas, std::ofstream &outFile);