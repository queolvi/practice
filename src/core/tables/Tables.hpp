#ifndef TABLES_HPP
#define TABLES_HPP
#include <string>
#include <functional>
#include <stdexcept>
#include <atomic>
#include <chrono>

enum class TaskStatus { ASSIGNED, IN_PROGRESS, SUBMITTED, GRADED};

class Course {
	private:
	unsigned long long course_id;
	std::string course_name, description;
	public:
	unsigned long long get_course_id () const;
	std::string get_course_name() const;
	std::string get_course_description() const;
};

class Assignment : private Course{
	private: 
	unsigned long long assignmnent_id;
	std::string title, description;
	std::chrono::year_month_day deadline;
	short max_score;
	bool allow_late_submission;

	public:
	unsigned long long get_assingment_id() const;
	std::string get_title () const;
	std::string get_description () const;
	std::chrono::year_month_day get_deadline() const;
	short get_max_score() const;
	bool is_overdue(std::chrono::year_month_day& rhs);
};

class Student{
	private:
	unsigned long long student_id;
	std::string first_name, last_name, email;
	public:
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
	unsigned long long get_teacher_id() const;
	Assignment create_assingment();
	void grade_submission(); 
};

class AssingmentSubmission{
	private:
	unsigned long long assingment_submission_id;
	Assignment* assignment_;
	Student* student_;
	Teacher* teacher_;
	std::chrono::year_month_day assigned_date;
	std::chrono::year_month_day submission_date;
	std::FILE* submission_file;
	short grade;
	TaskStatus status;

	public:
	bool submit();
	bool is_overdue(); 

	unsigned long long get_assingment_submission_id() const;
	short get_grade() const;
};

class AsignmentGroup{
	private:
	unsigned long long group_id;
	Assignment* assignment_;
	public:
	unsigned long long get_group_id() const;
};

#pragma once
#endif
