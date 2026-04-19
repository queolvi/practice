#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include <stdexcept>
#include <atomic>
#include "/../utils/Date/Date.hpp"

enum class TaskStatuses{ assigned, in_progress, submited, graded };
enum class Role { Student, Teacher, Administrator};
// (korp) for classes: autoincrement must be added to avoid duplicate id-s (inline static std::atomic<unsigned long long> id(1)) 

class User{
	unsigned long long user_id;
	Role role;
	std::string email;
	std::string phone;
	inline static std::atomic<unsigned long long> next_id{1};
	public:
	User(Role role, std::string phone, std::string email) : 
	user_id(next_id.fetch_add(1)), role(role), phone(phone), email(email) {
		// here running User Validator
	};
	User(const User&) = delete;
	User& operator=(const& User) = delete;
	User(User&&) noexcept = default;
	User& operator=(User&&) noexcept = default;
	
	unsigned long long get_user_id() const { return user_id; };
	static unsigned long long get_counter_id() { return next_id.load(); }
	static void reset_counter_id(unsigned long long rhs = 1) { next_id.store(rhs); }

	std::string get_user_role() const { return role; }
	std::string get_user_email() const { return email; }
	std::string get_user_phone() const { return phone; }
	
	void set_user_role(User_Role ur) { User_Role = ur; }
	void set_user_email(std::string& email_) { email = email_; }
	void set_user_phone(std::string& phone_) { phone = phone_; }
	void auth_user();
	
	virtual ~User() = default;
};

class Teacher : public User {
    size_t teacher_hash_password;
    std::string first_name;
    std::string last_name;
public:
    size_t get_teacher_hash() const { return teacher_hash_password; }
    void set_teacher_hash_password(const std::string& rhs) { 
        teacher_hash_password = std::hash<std::string>{}(rhs); 
    }
    
    Teacher(size_t teacher_hash_password, std::string first_name, std::string last_name, 
            std::string phone, std::string email) 
        : User(Role::Teacher, std::move(phone), std::move(email)), 
          teacher_hash_password(teacher_hash_password), 
          first_name(std::move(first_name)), 
          last_name(std::move(last_name)) {
        // here running Teacher Validator
    }
    ~Teacher() = default;
};

class Administrator : public User {
    size_t administrator_hash_password;
    std::string first_name;
    std::string last_name;
public:
    size_t get_administrator_hash_password() const { return administrator_hash_password; }
    void set_administrator_hash_password(const std::string& rhs) { 
        administrator_hash_password = std::hash<std::string>{}(rhs); 
    }
    
    Administrator(size_t administrator_hash_password, std::string first_name, std::string last_name,
                  std::string phone, std::string email) 
        : User(Role::Administrator, std::move(phone), std::move(email)),
          administrator_hash_password(administrator_hash_password),
          first_name(std::move(first_name)),
          last_name(std::move(last_name)) {
        // here running Administrator Validator
    }
    ~Administrator() = default;
};

class Student : public User {
    std::string first_name;
    std::string last_name;
    size_t student_hash;
public:
    size_t get_student_hash() const { return student_hash; }
    void set_student_hash(const std::string& rhs) {
        student_hash = std::hash<std::string>{}(rhs);
    }
    
    Student(size_t student_hash, std::string first_name, std::string last_name, 
            std::string phone, std::string email) 
        : User(Role::Student, std::move(phone), std::move(email)),
          first_name(std::move(first_name)),
          last_name(std::move(last_name)),
          student_hash(student_hash) {
        // here running Student Validator
    }
    ~Student() = default;
};

class Course{
	unsigned long long course_id;
	std::string course_name;	
	inline static std::atomic<unsigned long long> next_id{1};

	public:
	unsigned long long get_user_id() const { return course_id; };
	static unsigned long long get_counter_id() { return next_id.load(); }
	static void reset_counter_id(unsigned long long rhs = 1) { next_id.store(rhs); }

	Course(std::string course_name) : course_id(next_id.fetch_add(1)), course_name(course_name) {
		// here run Course Validator
	};
	Course(const Course&) = delete;
	Course& operator=(const Course&) = delete;
	Course(Course&&) noexcept = default;
	Course& operator=(Course&&) noexcept = default;
	~Course() = default;
};

class Assignmment{
	unsigned long long assignmment_id;
	std::string name, description;
	Date deadline;
	short max_score;
	inline static std::atomic<unsigned long long> next_id{1};
	public:
	
	unsigned long long get_user_id() const { return assignmment_id; };
	static unsigned long long get_counter_id() { return next_id.load(); }
	static void reset_counter_id(unsigned long long rhs = 1) { next_id.store(rhs); }

	Assignmment(std::string name, std::string description, Date deadline, short max_score) :
	assignmment_id(next_id.fetch_add(1)), name(name), description(description), deadline(deadline), max_score(max_score) {
		//run AssignmentSubmission Validator here
	};
	Assignmment(const Assignmment&) = delete;
	Assignmment& operator=(const Assignmment&) = delete;
	Assignmment(Assignmment&&) noexcept = default;
	Assignmment& operator=(Assignmment&&) noexcept = default;
	~Assignmment() = default;
};

class AssignmentSubmission : {
	unsigned long long assignment_submission_id;
	Date date_done;
	std::string path_to_file;
	short grade_for_assigned_submission;
	inline static std::atomic<unsigned long long> next_id{1};
	
	public:
	unsigned long long get_user_id() const { return assignment_submission_id; };
	static unsigned long long get_counter_id() { return next_id.load(); }
	static void reset_counter_id(unsigned long long rhs = 1) { next_id.store(rhs); }
	
	AssignmentSubmission(Date date_done, std::string path_to_file, short grade_for_assigned_submission) :
	assignment_submission_id(next_id.fetch_add(1)), date_done(date_done), path_to_file(path_to_file), grade_for_assigned_submission(grade_for_assigned_submission) {
		//run Assignment Submission Validator here
	};
	AssignmentSubmission(const AssignmentSubmission&) = delete;
	AssignmentSubmission& operator=(const AssignmentSubmission&) = delete;
	AssignmentSubmission(AssignmentSubmission&&) noexcept = default;
	AssignmentSubmission& operator=(AssignmentSubmission&&) noexcept = default;
	
	
	~AssignmentSubmission() = default;
};
class TaskStatus{
	private:
	TaskStatuses status;
	public:
	TaskStatus(TaskStatuses status) : status(status) {
		// run Task Validator here 
	};
	TaskStatus(const TaskStatus&) = delete;
	TaskStatust& operator=(const TaskStatus&) = delete;
	TaskStatus(TaskStatus&&) noexcept = default;
	TaskStatus& operator=(TaskStatus&&) noexcept = default;
	~TaskStatus() = default;
};


#pragma once
#endif
