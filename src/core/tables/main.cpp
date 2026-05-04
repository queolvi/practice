#include <iostream>
#include <chrono>
#include "Assignment/Assignment.hpp"
#include "AssignmentGroup/AssignmentGroup.hpp"
#include "AssignmentSubmission/AssignmentSubmission.hpp"
#include "Course/Course.hpp"
#include "Student/Student.hpp"
#include "TaskStatus/TaskStatus.hpp"
#include "Teacher/Teacher.hpp"
#include "../validator/Validator.hpp"
// only for test

int main () {
    #if 0
    Course course_ = {1, "Algebra", "Math lessons"};
    Assignment assign_= {1, "First assign", "assign", {April / 27 / 2026}, 100, 0};
    Student student_= {1, "Jack", "Compton", "email@example.exl", };
    Teacher teach_= {1, "Peter", "Holson"};
    std::FILE* file_to_assign_subm;
    AssingmentSubmission assign_subm_= {1, assign_, student_, teach_,
    assign_.get_deadline(), {April / 25 / 2026}, file_to_assign_subm, 5, TaskStatus::GRADED};
    AssignmentGroup assign_group_= {1, assign_};
#endif

Student st = {1 , "1", "2", "12345@gmail.con"};
StudentValidator st_valid = st;
st_valid.check_email();

    return 0;
}