#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"

class Student {
private:
    int id;
    std::string name;
    double gpa;
    Course* courseHead;

public:
    Student(int id, const std::string& name, double gpa);
    ~Student();

    int getId() const;
    void addCourse(const std::string& name, const std::string& location);
    void display() const;
};

#endif
