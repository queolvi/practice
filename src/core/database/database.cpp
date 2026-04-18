#include "database.cpp"
std::string SimpleDatabase::input_table_name () {
        std::string user_input;
        std::cin >> user_input;
        return user_input;
}

template<typename T>
std::string SimpleDatabase::input_table_fields(std::string table_name, std::pair<std::vector<T>,
std::vector<T>> types_and_fields) {
    std::cin >> 

}