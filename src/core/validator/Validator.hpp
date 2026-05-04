
#include "Assignment/Assignment.hpp"
#include "AssignmentGroup/AssignmentGroup.hpp"
#include "AssignmentSubmission/AssignmentSubmission.hpp"
#include "Course/Course.hpp"
#include "Student/Student.hpp"
#include "Teacher/Teacher.hpp"
#include "../utils/Utils.hpp"

#include <climits>
class Validator{
    public:
    std::string table_name;
    Validator(std::string table_name) : table_name(table_name) {}
    virtual ~Validator() = default;
    virtual bool is_valide() {};
};

class StudentValidator : public Validator {
    private:
    Student student_;
    public:
    StudentValidator(Student student_) : student_(student_) {}
    bool is_valide() override;
    bool check_email();
    bool check_first_name();
    bool check_second_name();
    bool check_student_id();
};
class AssignmnentValidator : public Validator {
    bool is_valide() override;
};
class AssignmentGroupValidator : public Validator {
    bool is_valide() override;
};
class AssignmentSubmissionValidator : public Validator {
    bool is_valide() override;
};
class CourseValidator : public Validator {
    bool is_valide() override;
};
class TeacherValidator : public Validator {
    bool is_valide() override;

};
