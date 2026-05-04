#include "../Assignment/Assignment.hpp"

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