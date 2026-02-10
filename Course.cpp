#include "Course.hpp"

Course::Course(const std::string& name, const std::string& location)
    : name(name), location(location), next(nullptr) {}
