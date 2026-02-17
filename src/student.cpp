#include <student.h>

Student::Student(const std::string &name, float gpa) : name(name), gpa(gpa) {};

std::string Student::getName() const {
    return name;
}

float Student::getGPA() const {
    return gpa;
}