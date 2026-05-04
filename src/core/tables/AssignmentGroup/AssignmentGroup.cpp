#include "AssignmentGroup.hpp"

AssignmentGroup::AssignmentGroup(unsigned long long group_id, Assignment* assignment_) : group_id(group_id), assignment_(assignment_) {}
unsigned long long AssignmentGroup::get_group_id() const { return group_id; }
