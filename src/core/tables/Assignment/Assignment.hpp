#include <string>
#include <chrono>
#include "../Course/Course.hpp"

using namespace std::chrono;
class Assignment{
	private: 
	unsigned long long assignmnent_id;
	std::string title, assignment_description;
	year_month_day deadline;
	short max_score;
	bool allow_late_submission;
	Course* course;
	public:
	Assignment(unsigned long long assignmnent_id, std::string title, std::string assignment_description, year_month_day deadline, short max_score, bool allow_late_submission);
	unsigned long long get_assingment_id() const;
	std::string get_title () const;
	std::string get_description () const;
	year_month_day get_deadline() const;
	short get_max_score() const;
	bool is_overdue(year_month_day& rhs);
};