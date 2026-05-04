#include <string>

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