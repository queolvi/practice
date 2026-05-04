#include "Course.hpp"

Course::Course(unsigned long long course_id, std::string course_name, std::string description) : course_id(course_id), course_name(course_name), description(description) {}
unsigned long long Course::get_course_id () const { return course_id; }
std::string Course::get_course_name() const { return course_name; }
std::string Course::get_course_description() const { return description; }

