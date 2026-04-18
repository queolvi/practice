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
    std::vector<Table> Tables = {Users, }
    
};