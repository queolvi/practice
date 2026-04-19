#include "/../tables/Tables.hpp"

class Validator{
    public:
    std::string table_name;
    Validator(std::string table_name) : table_name(table_name) {}
    ~Validator() = default;
    virtual bool is_valide() {};
};
class UserValidator : public Validator, private User {
      
};

class UserValidator : public Validator, private User {
      
};