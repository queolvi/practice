#include <fstream>
#include <utility>
class SimpleDatabase{
    public:
    std::string path;
    SimpleDatabase(std::string path) : path(path) {};
    ~SimpleDatabase();
    std::string input_table_name () {}
    template<typename T>
    std::string input_table_fields(std::pair<std::vector<T>, std::vector<T>> types_and_fields) {}
    private:
    std::FILE* db_file;
    
    std::string table_name;
    
    template <typename T>
    
    std::vector <T> fields;
    std::vector <string> fields_type;

    public:
    template<typename T>
    int create_table(std::pair<std::string, T> table);
    
    template<typename T>
    std::vector select(T args);

};