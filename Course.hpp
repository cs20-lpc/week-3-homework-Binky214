#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course {
public:
    std::string name;
    std::string location;
    Course* next;

    Course(const std::string& name, const std::string& location);
};

#endif
