#include "../Assignment/Assignment.hpp"

class AssignmentGroup{
	private:
	unsigned long long group_id;
	Assignment* assignment_;
	public:
	AssignmentGroup(unsigned long long group_id, Assignment* assignment_);
	unsigned long long get_group_id() const;
};