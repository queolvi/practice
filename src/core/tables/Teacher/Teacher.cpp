#include "Teacher.hpp"

Teacher::Teacher(unsigned long long teacher_id, std::string first_name,
std::string last_name) : teacher_id(teacher_id), first_name(first_name), last_name(last_name) {}
unsigned long long Teacher::get_teacher_id() const { return teacher_id; }

Assignment Teacher::create_assingment(unsigned long long id_assignment_, std::string title_, std::string description_,
year_month_day deadline_, short max_score_, bool allow_late_submission) {
    Assignment curr_assignment = {id_assignment_, title_, description_, deadline_, max_score_, allow_late_submission};
    return curr_assignment;
}
void Teacher::grade_submission() {}
