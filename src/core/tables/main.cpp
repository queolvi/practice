#include <iostream>
#include <chrono>
#include "Tables.hpp"
// only for test

int main () {
    
    Course course_ = {1, "Algebra", "Math lessons"};
    Assignment assign_= {1, "First assign", "assign", {April / 27 / 2026}, 100, 0};
    Student student_= {1, "Jack", "Compton", "email@example.exl", };
    Teacher teach_= {1, "Peter", "Holson"};
    std::FILE* file_to_assign_subm;
    AssingmentSubmission assign_subm_= {1, assign_, student_, teach_,
    assign_.get_deadline(), {April / 25 / 2026}, file_to_assign_subm, 5, TaskStatus::GRADED};
    AssignmentGroup assign_group_= {1, assign_};
    return 0;
}