#include <string>

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