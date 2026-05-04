#include "AssignmentGroup.hpp"

AssignmentGroup::AssignmentGroup(unsigned long long group_id, Assignment* assignment_)
: group_id(group_id), assignment_(assignment_) {
    if ((group_id >= 1 && group_id <= std::numeric_limits<unsigned long long >::max())
    && assignment_ != nullptr)  {

    } else {
        throw std::runtime_error("Error, invalid parameters for AssignedGroup Constructor");
    }
}
unsigned long long AssignmentGroup::get_group_id() const { return group_id; }
