#pragma once

#include <string>

class Student {
private:
    std::string name;
    float gpa;

public:
    Student(const std::string &name, const float gpa);

    std::string getName() const;
    float getGPA() const;
};