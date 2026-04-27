#include "Tables.hpp"
Course::Course(unsigned long long course_id, std::string course_name, std::string description) : course_id(course_id), course_name(course_name), description(description) {}
unsigned long long Course::get_course_id () const { return course_id; }
std::string Course::get_course_name() const { return course_name; }
std::string Course::get_course_description() const { return description; }


    Assignment::Assignment(unsigned long long assignmnent_id, std::string title, std::string assignment_description, year_month_day deadline, short max_score, bool allow_late_submission) :
assignmnent_id(assignmnent_id), title(title), assignment_description(assignment_description), deadline(deadline), max_score(max_score), allow_late_submission(allow_late_submission) {}

unsigned long long Assignment::get_assingment_id() const { return assignmnent_id; }
std::string Assignment::get_title () const { return title; }
std::string Assignment::get_description () const { return assignment_description; }
year_month_day Assignment::get_deadline() const { return deadline; }
short Assignment::get_max_score() const { return max_score; }

bool Assignment::is_overdue(year_month_day& rhs) { 
    year_month_day gets_deadline = get_deadline();
    if (rhs > gets_deadline) { return true; }
    return false;
}

Student::Student(unsigned long long student_id, std::string first_name,
std::string last_name, std::string email) : student_id(student_id), first_name(first_name), last_name(last_name), email(email) {}
std::string Student::get_first_name() const { return first_name; }
std::string Student::get_last_name() const { return last_name; }
std::string Student::get_email() const { return email; }

Teacher::Teacher(unsigned long long teacher_id, std::string first_name,
std::string last_name) : teacher_id(teacher_id), first_name(first_name), last_name(last_name) {}
unsigned long long Teacher::get_teacher_id() const { return teacher_id; }

Assignment Teacher::create_assingment(unsigned long long id_assignment_, std::string title_, std::string description_,
year_month_day deadline_, short max_score_, bool allow_late_submission) {
    Assignment curr_assignment = {id_assignment_, title_, description_, deadline_, max_score_, allow_late_submission};
    return curr_assignment;
}
void Teacher::grade_submission() {}

AssingmentSubmission::AssingmentSubmission(unsigned long long assingment_submission_id, Assignment* assignment_,
	Student* student_, Teacher* teacher_, year_month_day assigned_date, year_month_day submission_date,
	std::FILE* submission_file, short grade, TaskStatus status) : assingment_submission_id(assingment_submission_id), assignment_(assignment_),
    student_(student_), teacher_(teacher_), assigned_date(assigned_date), submission_date(submission_date), submission_file(submission_file), grade(grade), status(status) {}

AssignmentGroup::AssignmentGroup(unsigned long long group_id, Assignment* assignment_) : group_id(group_id), assignment_(assignment_) {}
unsigned long long AssignmentGroup::get_group_id() const { return group_id; }