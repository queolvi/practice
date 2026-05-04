#include <iostream>
#include <chrono>
#include "../Assignment/Assignment.hpp"

using namespace std::chrono;
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