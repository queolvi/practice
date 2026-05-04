#include "../Assignment/Assignment.hpp"

Assignment::Assignment(unsigned long long assignmnent_id
                    , std::string title
                    , std::string assignment_description
                    , year_month_day deadline
                    , short max_score
                    , bool allow_late_submission
                    , TaskStatus status) :
assignmnent_id(assignmnent_id), title(title),
assignment_description(assignment_description),
deadline(deadline), max_score(max_score),
allow_late_submission(allow_late_submission) ,
status(status) {
    if ((assignmnent_id >= 1 || assignmnent_id <= std::numeric_limits<size_t>::max()) 
    && (title != "0") && (assignment_description != "") &&
    (deadline >=  std::numeric_limits<year_month_day>::min() && deadline <= std::numeric_limits<year_month_day>::min()) 
    && (max_score >= std::numeric_limits<short>::min() && max_score <= std::numeric_limits<short>::max())
    && (allow_late_submission == false) && (status == TaskStatus::ASSIGNED) 
    ) {}
    else {
        throw std::runtime_error("Error, invalid parameters for Assigned Constructor");
    }
}

unsigned long long Assignment::get_assingment_id() const { return assignmnent_id; }
std::string Assignment::get_title () const { return title; }
std::string Assignment::get_description () const { return assignment_description; }
year_month_day Assignment::get_deadline() const { return deadline; }
short Assignment::get_max_score() const { return max_score; }
TaskStatus Assignment::get_status() const { return status; }
bool Assignment::is_overdue(year_month_day& rhs) { 
    year_month_day gets_deadline = get_deadline();
    if (rhs > gets_deadline) { return true; }
    return false;
}