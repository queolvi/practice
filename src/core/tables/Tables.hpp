#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include <stdexcept>
#include "/../utils/Date/Date.hpp"

enum TaskStatuses{ assigned, in_progress, submited, graded };
enum Roles { Student_, Teacher_, Administrator_};
// (korp) for classes: autoincrement must be added to avoid duplicate id-s (inline static std::atomic<unsigned long long> id(1)) 
class UserRole{
	unsigned long long role_id;
	std::string role;
	public:
	void settring_role(std::string rhs) const { return rhs = role; }
	std::string get_role() const { return role; };
	User_Role(std::string role) : role(role) { if ( role_id >= 1 && role_id <= 3) {}
	 else {
		throw std::logic_error("Not contains in roles number");
	  }
	}
	~User_Role() = default;
};

class User{
	unsigned long long id;
	std::string User_Role;
	std::string email;
	std::string phone;
	public:
	std::string get_user_role() const { return User_Role; }
	std::string get_user_email() const { return email; }
	std::string get_user_phone() const { return phone; }
	void set_user_role(User_Role ur) { User_Role = ur; }
	void set_user_email(std::string& email_) { email = email_; }
	void set_user_phone(std::string& phone_) { phone = phone_; }
	void auth_user();
	
	User();
	~User() = default;
};
class Teacher{
	unsigned long long teacher_id;
	size_t teacher_hash_password;
	std::string first_name;
	std::string last_name;
	public:
	size_t get_teacher_hash() { return teacher_hash_password };
	void get_teacher_hash(std::string& rhs) {};
	Teacher();
	~Teacher() = default;
};
class Administrator{
	unsigned long long administrator_id;
	size_t administrator_hash_password;
	std::string first_name;
	std::string last_name;
	public:
	size_t get_administrator_hash_password();
	void set_administrator_hash_password(std::string& rhs) { std::hash<std::string>{}(rhs); }
	Administrator();
	~Administrator() = default;
};
class Course{
	std::string course_name;	
	unsigned long long course_id;
	public:
	Course();
	~Course() = default;
};

class Assignmment{
	unsigned long long assignmment_id;
	std::string name, description;
	Date deadline;
	short max_score;
	public:
	Assignmment();
	~Assignmment() = default;
};
class Student{
	unsigned long long student_id;
	std::string first_name;
	std::string last_name;
	size_t student_hash;
	public:
	size_t get_student_hash();
	Student();
	~Student() = default;
};
class AssignmentSubmission{
	unsigned long long assignment_submission_id;
	public:
	AssignmentSubmission();
	~AssignmentSubmission() = default;
};
class TaskStatus{
	private:
	unsigned long long task_status_id;
	public:
	TaskStatus();
	~TaskStatus() = default;
};


#pragma once
#endif
