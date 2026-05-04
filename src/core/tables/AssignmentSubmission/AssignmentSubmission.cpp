#include "AssignmentSubmission.hpp"
AssingmentSubmission::AssingmentSubmission(unsigned long long assingment_submission_id, Assignment* assignment_,
	Student* student_, Teacher* teacher_, year_month_day assigned_date, year_month_day submission_date,
	std::FILE* submission_file, short grade, TaskStatus status) : assingment_submission_id(assingment_submission_id), assignment_(assignment_),
    student_(student_), teacher_(teacher_), assigned_date(assigned_date), submission_date(submission_date), submission_file(submission_file), grade(grade), status(status) {}

