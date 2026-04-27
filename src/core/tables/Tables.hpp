#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include <stdexcept>
#include <atomic>
#include <chrono>

//namespace {
using namespace std::chrono;
enum class TaskStatus { ASSIGNED, IN_PROGRESS, SUBMITTED, GRADED};
class Course {
	private:
	unsigned long long course_id;
	std::string course_name, description;
	public:
	Course(unsigned long long course_id, std::string course_name, std::string description);
	unsigned long long get_course_id () const;
	std::string get_course_name() const;
	std::string get_course_description() const;
};

class Assignment{
	private: 
	unsigned long long assignmnent_id;
	std::string title, assignment_description;
	year_month_day deadline;
	short max_score;
	bool allow_late_submission;
	Course* course;
	public:
	Assignment(unsigned long long assignmnent_id, std::string title, std::string assignment_description, year_month_day deadline, short max_score, bool allow_late_submission);
	unsigned long long get_assingment_id() const;
	std::string get_title () const;
	std::string get_description () const;
	year_month_day get_deadline() const;
	short get_max_score() const;
	bool is_overdue(year_month_day& rhs);
};

class Student{
	private:
	unsigned long long student_id;
	std::string first_name, last_name, email;
	public:
	Student(unsigned long long student_id, std::string first_name, std::string last_name, std::string email);
	unsigned long long get_student_id() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_email() const;
};

class Teacher{
	private:
	unsigned long long teacher_id;
	std::string first_name, last_name;
	public:
	Teacher(unsigned long long teacher_id, std::string first_name, std::string last_name);
	unsigned long long get_teacher_id() const;
	Assignment create_assingment(unsigned long long id_assignment_, std::string title_, std::string description_,
	year_month_day deadline_, short max_score_, bool allow_late_submission);
	void grade_submission(); 
};

class AssingmentSubmission{
	private:
	unsigned long long assingment_submission_id;
	Assignment* assignment_;
	Student* student_;
	Teacher* teacher_;
	year_month_day assigned_date;
	year_month_day submission_date;
	std::FILE* submission_file;
	short grade;
	TaskStatus status;

	public:
	AssingmentSubmission(unsigned long long assingment_submission_id, Assignment* assignment_,
	Student* student_, Teacher* teacher_, year_month_day assigned_date, year_month_day submission_date,
	std::FILE* submission_file, short grade, TaskStatus status);
	bool submit();
	bool is_overdue(); 

	unsigned long long get_assingment_submission_id() const;
	short get_grade() const;
};

class AssignmentGroup{
	private:
	unsigned long long group_id;
	Assignment* assignment_;
	public:
	AssignmentGroup(unsigned long long group_id, Assignment* assignment_);
	unsigned long long get_group_id() const;
};
// end namespace
//};
#pragma once
#endif
