#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include "/../utils/Date/Date.hpp"

enum TaskStatuses{ assigned, in_progress, submited, graded };
enum Roles { Student_, Teacher_, Administrator_};

class UserRole{};

class User{
	unsigned short id;
	std::string User_Role;
};
class Teacher{
	unsigned short id;
};
class Administrator{
	unsigned short id;
};
class Course{
	unsigned short course_id;
};

class Assignmment{
	unsigned short assignmment_id;
	std::string name, description;
	Date deadline;
	short max_score;
};
class Student{
	unsigned student_id;
	std::string first_name;
	std::string last_name;
};
class AssignmentSubmission{
	unsigned short assignment_submission_id;
	
};
class TaskStatus{
	unsigned short task_status_id;
};


#pragma once
#endif
