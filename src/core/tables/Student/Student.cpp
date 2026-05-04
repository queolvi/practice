#include "Student.hpp"

Student::Student(unsigned long long student_id, std::string first_name,
std::string last_name, std::string email) : student_id(student_id), first_name(first_name), last_name(last_name), email(email) {}
std::string Student::get_first_name() const { return first_name; }
std::string Student::get_last_name() const { return last_name; }
std::string Student::get_email() const { return email; }
