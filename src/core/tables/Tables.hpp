#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include "/../utils/Date/Date.hpp"

enum TaskStatuses{ assigned, in_progress, submited, graded };
enum Roles { Student_, Teacher_, Administrator_};

class UserRole{
	std::string role;
	public:
	void set_role(std::string rhs) const { return rhs = role; return role; }
	User_Role(std::string role) : role(role) {}
	~User_Role();
};

class User{
	unsigned long long id;
	std::string User_Role;
	std::string email;
	std::string phone;
	public:
	User();
	~User();
};
class Teacher{
	unsigned long long id;
	std::hash<std::string> hash_password;
	std::string first_name;
	std::string last_name;
	public:
	Teacher();
	~Teacher();
};
class Administrator{
	unsigned long long id;
	std::hash<std::string> hash_password;
	std::string first_name;
	std::string last_name;
	public:
	Administrator();
	~Administrator();
};
class Course{
	std::string course_name;	
	unsigned long long course_id;
	public:
	Course();
	~Course();
};

class Assignmment{
	unsigned long long assignmment_id;
	std::string name, description;
	Date deadline;
	short max_score;
	public:
	Assignmment();
	~Assignmment();
};
class Student{
	unsigned long long student_id;
	std::string first_name;
	std::string last_name;
	public:
	Student();
	~Student();
};
class AssignmentSubmission{
	unsigned long long assignment_submission_id;
	public:
	AssignmentSubmission();
	~AssignmentSubmission();
};
class TaskStatus{
	private:
	unsigned long long task_status_id;
	public:
	TaskStatus();
	~TaskStatus();
};


#pragma once
#endif
