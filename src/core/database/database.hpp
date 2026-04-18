#include <fstream>
#include <utility>
#include "/../tables/Tables.hpp"

template <typename T>
using Table = std::vector<std::vector<T>>; 
class SimpleDatabase{
    public:
    std::string path;
    SimpleDatabase(std::string path) : path(path) {};
    ~SimpleDatabase();
    private:
    std::FILE* db_file;
    std::string table_name;
    std::vector<Table> Tables = 
    {User, Teacher, Administrator,
    Course, Student, AssignmentSubmission,
    TaskStatus};
    unsigned long long query_id;
    bool is_saving_query_id_on;
    
    template <typename T>
    int select(std::string table_name, std::vector<T> fields_numbers, std::string options) {}; 
    
    template <typename T>
    int delete(std::string table_name, std::vector<T> fields_numbers, std::string options) {};
    
    template <typename T>
    int update(std::string table_name, std::vector<T> fields_numbers, std::string options) {};
    
    template <typename T>
    int insert(std::string table_name, std::vector<T> fields_numbers, std::string options) {};
    
    // (korp) dont forget add validation before every query
};