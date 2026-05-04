#include "../Assignment/Assignment.hpp"
#include "../Student/Student.hpp"
#include "../Teacher/Teacher.hpp"
#include "../TaskStatus/TaskStatus.hpp"

class AssingmentSubmission{
	private:
	unsigned long long assingment_submission_id;
	Assignment* assignment_;
	Student* student_;
	Teacher* teacher_;
	year_month_day assigned_date;
	year_month_day submission_date;
	std::FILE* submission_file;
	short grade;
	TaskStatus status;

	public:
	AssingmentSubmission(unsigned long long assingment_submission_id, Assignment* assignment_,
	Student* student_, Teacher* teacher_, year_month_day assigned_date, year_month_day submission_date,
	std::FILE* submission_file, short grade, TaskStatus status);
	bool submit();
	bool is_overdue(); 

	unsigned long long get_assingment_submission_id() const;
	short get_grade() const;
};