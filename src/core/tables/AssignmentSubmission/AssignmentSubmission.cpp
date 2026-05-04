#include "AssignmentSubmission.hpp"
AssingmentSubmission::AssingmentSubmission(unsigned long long assingment_submission_id, Assignment assignment_,
	std::vector<Student> student_, Teacher teacher_, year_month_day assigned_date, year_month_day submission_date,
	std::FILE* submission_file, short grade, TaskStatus status) :
	
	assingment_submission_id(assingment_submission_id),
	assignment_(assignment_), student_ (std::move(student_)),
	teacher_(teacher_), assigned_date(assigned_date),
	submission_date(submission_date), submission_file(submission_file),
	grade(grade), status(status) {
			if ((assingment_submission_id >= 1) && ( && assignment_)
	}

bool AssingmentSubmission::submit() {
	if (assignment_.get_status() == TaskStatus::ASSIGNED || assignment_.get_status() == TaskStatus::IN_PROGRESS) { throw std::runtime_error("Can`t give task to student with this statuses again"); return false; }
	else { return true;}
}
bool AssingmentSubmission::is_overdue() {
	if (submission_date > assignment_.get_deadline()) { return false; }
	return true;
}

unsigned long long AssingmentSubmission::get_assingment_submission_id() const { return assingment_submission_id; }
short AssingmentSubmission::get_grade() const { return grade; }
