#include "Tables.hpp"

unsigned long long Course::get_course_id () const { return course_id; }
std::string Course::get_course_name() const { return course_name; }
std::string Course::get_course_description() const { return description; }

unsigned long long Assignment::get_assingment_id() const { return assignmnent_id; }
std::string Assignment::get_title () const { return title; }
std::string Assignment::get_description () const { return description; }
std::chrono::year_month_day Assignment::get_deadline() const { return deadline; }
short Assignment::get_max_score() const { return max_score; }

bool Assignment::is_overdue(std::chrono::year_month_day& rhs) { 
    std::chrono::year_month_day gets_deadline = get_deadline();
    if (rhs > gets_deadline) { return true; }
    return false;
}

std::string Student::get_first_name() const { return first_name; }
std::string Student::get_last_name() const { return last_name; }
std::string Student::get_email() const { return email; }

unsigned long long Teacher::get_teacher_id() const {}
Assignment Teacher::create_assingment() {}
void Teacher::grade_submission() {}