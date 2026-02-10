#include "Student.hpp"
#include <iostream>

Student::Student(int id, const std::string& name, double gpa)
    : id(id), name(name), gpa(gpa), courseHead(nullptr) {}

Student::~Student() {
    Course* current = courseHead;
    while (current != nullptr) {
        Course* temp = current;
        current = current->next;
        delete temp;
    }
}

int Student::getId() const {
    return id;
}

void Student::addCourse(const std::string& name, const std::string& location) {
    Course* newCourse = new Course(name, location);

    if (!courseHead) {
        courseHead = newCourse;
        return;
    }

    Course* current = courseHead;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newCourse;
}

void Student::display() const {
    std::cout << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "GPA: " << gpa << "\n"
              << "Courses:\n";

    Course* current = courseHead;
    if (!current) {
        std::cout << "  None\n";
    }

    while (current) {
        std::cout << "  - " << current->name
                  << " (" << current->location << ")\n";
        current = current->next;
    }
}
